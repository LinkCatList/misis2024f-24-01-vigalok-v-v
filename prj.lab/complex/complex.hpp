#pragma once

#include <fstream>
#include <iostream>

#define EPS 1e-5

struct Complex {
public:
    Complex () {
        Real = 0;
        Imaginary = 0;
    }

    Complex (const double real, const double imaginary)
    : Real(real), Imaginary(imaginary)
    {}

    Complex (const double real)
    : Real(real), Imaginary(0)
    {}

public:
    double GetReal() const;
    double GetImaginary() const;

    void SetReal(const double OtherReal);
    void SetImaginary(const double OtherImaginary);

public:
    bool operator ==(const Complex& otherComplex) const {
        return abs(Real - otherComplex.Real) <= EPS && abs(Imaginary == otherComplex.Imaginary) <= EPS;
    }

    bool operator !=(const Complex& otherComplex) const {
        return *this != otherComplex;
    }

public:
    Complex& operator =(const Complex& otherComplex) = default;

    Complex& operator +=(const Complex& otherComplex);
    Complex& operator +=(const double otherReal);
    Complex& operator -=(const Complex& otherComplex);
    Complex& operator -=(const double otherReal);
    Complex& operator *=(const Complex& otherComplex);
    Complex& operator *=(const double otherReal);
    Complex& operator /=(const double otherReal);

    friend Complex operator +(const Complex& lhs, const Complex& rhs);
    friend Complex operator -(const Complex& lhs, const Complex& rhs);
    friend Complex operator *(const Complex& lhs, const Complex& rhs);
    friend Complex operator /(const Complex& complex, const double otherReal);

public:
    std::ostream& WriteTo(std::ostream& ostrm) const;
    std::istream& ReadFrom(std::istream& istrm);

public:
    friend std::ostream& operator <<(std::ostream& ostrm, const Complex& c);
    friend std::istream& operator >>(std::istream& istrm, Complex& c);

private:
    double Real;
    double Imaginary;

public:
    static const char LeftBrace = '{';
    static const char Separator = ',';
    static const char RightBrace = '}';
};
