#include <rational/rational.hpp>

#include <numeric>

int Rational::Gcd(int a, int b) {
    return std::gcd(a, b);
}

int Rational::Lcm(int a, int b) {
    return a * b / Gcd(a, b);
}

void Rational::Normalize() {
    int gcd = Gcd(Numerator, Denumerator);
    Numerator /= gcd;
    Denumerator /= gcd;
    if (Denumerator < 0) {
        Numerator *= (-1);
        Denumerator *= (-1);
    }
}

bool Rational::operator ==(const Rational& otherRational) const {
    return Numerator == otherRational.Numerator && Denumerator == otherRational .Denumerator;
}

bool Rational::operator !=(const Rational& otherRational) const {
    return !(*this == otherRational);
}

bool Rational::operator <(const Rational& otherRational) const {
    int lcm = Lcm(Denumerator, otherRational.Denumerator);
    return Numerator * (lcm / Denumerator) < otherRational.Numerator * (lcm / otherRational.Denumerator);
}

bool Rational::operator >(const Rational& otherRational) const {
    return otherRational < *this;
}

bool Rational::operator <=(const Rational& otherRational) const {
    return *this < otherRational || *this == otherRational;
}

bool Rational::operator >=(const Rational& otherRational) const {
    return *this > otherRational || *this == otherRational;
}

Rational& Rational::operator +=(const Rational& otherRational) {
    int lcm = Lcm(Denumerator, otherRational.Denumerator);
    Numerator *= (lcm / Denumerator);
    Numerator += otherRational.Numerator * (lcm / otherRational.Denumerator);
    Denumerator = lcm;
    Normalize();
    return *this;
}

Rational& Rational::operator -=(const Rational& otherRational) {
    int lcm = Lcm(Denumerator, otherRational.Denumerator);
    Numerator *= (lcm / Denumerator);
    Numerator -= otherRational.Numerator * (lcm / otherRational.Denumerator);
    Denumerator = lcm;
    Normalize();
    return *this;
}

Rational& Rational::operator *=(const Rational& otherRational) {
    Numerator *= otherRational.Numerator;
    Denumerator *= otherRational.Denumerator;
    Normalize();
    return *this;
}

Rational& Rational::operator /=(const Rational& otherRational) {
    Numerator *= otherRational.Denumerator;
    Denumerator *= otherRational.Numerator;
    Normalize();
    return *this;
}

Rational operator +(const Rational& lhs, const Rational& rhs) {
    int lcm = Rational::Lcm(lhs.Denumerator, rhs.Denumerator);
    Rational sumRational = lhs;
    sumRational.Numerator *= (lcm / sumRational.Denumerator);
    sumRational += rhs.Numerator * (lcm / rhs.Denumerator);
    sumRational.Denumerator = lcm;
    sumRational.Normalize();
    return sumRational;
}

Rational operator -(const Rational& lhs, const Rational& rhs) {
    int lcm = Rational::Lcm(lhs.Denumerator, rhs.Denumerator);
    Rational difRational = lhs;
    difRational.Numerator *= (lcm / difRational.Denumerator);
    difRational -= rhs.Numerator * (lcm / rhs.Denumerator);
    difRational.Denumerator = lcm;
    difRational.Normalize();
    return difRational;
}

Rational operator *(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator * rhs.Numerator, lhs.Denumerator * rhs.Denumerator);
}

Rational operator /(const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator * rhs.Denumerator, lhs.Denumerator * rhs.Numerator);
}

std::ostream& Rational::WriteTo(std::ostream& ostrm) const {
    ostrm << LeftBrace << Numerator << Separator << Denumerator << RightBrace;
    return ostrm;
}

std::istream& Rational::ReadFrom(std::istream& istrm) {
    char leftBrace = '{';
    char separator = '/';
    char rightBrace = '}';
    Rational otherRational;

    istrm >> leftBrace >> otherRational.Numerator >> separator >> otherRational.Denumerator >> rightBrace;
    if (istrm.good()) {
        if (leftBrace == LeftBrace && separator == Separator && rightBrace == RightBrace) {
            Numerator = otherRational.Numerator;
            Denumerator = otherRational.Denumerator;
            Normalize();
        }
        else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}

std::ostream& operator <<(std::ostream& ostrm, const Rational& c) {
    return c.WriteTo(ostrm);
}

std::istream& operator >>(std::istream& istrm, Rational& c) {
    return c.ReadFrom(istrm);
}
