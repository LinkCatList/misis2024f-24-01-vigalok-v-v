#pragma once

#include <ostream>
#include <iostream>

class Rational {
public:
    Rational()
    : Numerator(0)
    , Denumerator(1)
    {}

    Rational(int numerator, int denumerator = 1)
    : Numerator(numerator)
    , Denumerator(denumerator)
    {
        Normalize();
    }

    Rational(const Rational& otherRational) {
        Numerator = otherRational.Numerator;
        Denumerator = otherRational.Denumerator;
        this->Normalize();
    }

public:
    void Normalize();

private:
    static int Gcd(int lhs, int rhs);
    static int Lcm(int a, int b);

public:
    bool operator ==(const Rational& otherRational) const;
    bool operator !=(const Rational& otherRational) const;
    bool operator <(const Rational& otherRational) const;
    bool operator >(const Rational& otherRational) const;
    bool operator <=(const Rational& otherRational) const;
    bool operator >=(const Rational& otherRational) const;

    Rational& operator +=(const Rational& otherRational);
    Rational& operator -=(const Rational& otherRational);
    Rational& operator /=(const Rational& otherRational);
    Rational& operator *=(const Rational& otherRational);

    friend Rational operator +(const Rational& lhs, const Rational& rhs);
    friend Rational operator -(const Rational& lhs, const Rational& rhs);
    friend Rational operator *(const Rational& lhs, const Rational& rhs);
    friend Rational operator /(const Rational& lhs, const Rational& rhs);

public:
    std::ostream& WriteTo(std::ostream& ostrm) const;
    std::istream& ReadFrom(std::istream& istrm);

public:
    friend std::ostream& operator <<(std::ostream& ostrm, const Rational& c);
    friend std::istream& operator >>(std::istream& istrm, Rational& c);

private:
    int Numerator = 0;
    int Denumerator = 1;

public:
    static const char LeftBrace = '{';
    static const char Separator = '/';
    static const char RightBrace = '}';

};