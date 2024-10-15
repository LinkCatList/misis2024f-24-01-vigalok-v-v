#include "complex.h"

double Complex::GetReal() {
    return Real;
}

double Complex::GetImaginary() {
    return Imaginary;
}

void Complex::SetReal(const double OtherReal) {
    Real = OtherReal;
}

void Complex::SetImaginary(const double OtherImaginary) {
    Imaginary = OtherImaginary;
}

Complex& Complex::operator +=(const Complex& otherComplex) {
    Real += otherComplex.Real;
    Imaginary += otherComplex.Imaginary;
    return *this;
}

Complex& Complex::operator +=(const double otherReal) {
   return *this += Complex(otherReal);
}

Complex& Complex::operator -=(const Complex& otherComplex) {
    Real -= otherComplex.Real;
    Imaginary -= otherComplex.Imaginary;
    return *this;
}

Complex& Complex::operator -=(const double otherReal) {
   return *this -= Complex(otherReal);
}

Complex& Complex::operator *=(const Complex& otherComplex) {
    Complex mult;
    mult.Real = Real * otherComplex.Real - Imaginary * otherComplex.Imaginary;
    mult.Imaginary = Imaginary * otherComplex.Real + Real * otherComplex.Imaginary;
    return *this = mult;
}

Complex& Complex::operator *=(const double otherReal) {
   return *this *= Complex(otherReal);
}

Complex operator +(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs.Real + rhs.Real, lhs.Imaginary + rhs.Imaginary);
}

Complex operator -(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs.Real - rhs.Real, lhs.Imaginary - rhs.Imaginary);
}

Complex operator *(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs.Real * rhs.Real - lhs.Imaginary * rhs.Imaginary, lhs.Imaginary * rhs.Imaginary + lhs.Real * rhs.Real);
}

std::ostream& Complex::WriteTo(std::ostream& ostrm) const {
    ostrm << LeftBrace << Real << Separator << Imaginary << RightBrace;
    return ostrm;
}

std::istream& Complex::ReadFrom(std::istream& istrm) {
    char leftBrace = ' ';
    char separator = ' ';
    char rightBrace = ' ';
    Complex otherComplex;

    istrm >> leftBrace >> otherComplex.Real >> separator >> otherComplex.Imaginary >> rightBrace;
    if (istrm.good()) {
        if (leftBrace == LeftBrace && separator == Separator && rightBrace == RightBrace) {
            Real = otherComplex.Real;
            Imaginary = otherComplex.Imaginary;
        }
        else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}

std::ostream& operator <<(std::ostream& ostrm, const Complex& c) {
    return c.WriteTo(ostrm);
}

std::istream& operator >>(std::istream& istrm, Complex& c) {
    return c.ReadFrom(istrm);
}
