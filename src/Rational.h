#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
using namespace std;

class student; // forward declaration

class Rational
{
    int numerator;
    int denominator;

    int gcd(int a, int b);

public:
    friend istream& operator>>(istream& input, student& s);
    friend ostream& operator<<(ostream& output, student& s);

    Rational();
    Rational(int x1, int x2);

    int getnumerator();
    int getdenominator();
    int setNumerator(int n);
    int setDenominator(int d);

    Rational operator+(Rational n1) const;
    Rational operator-(Rational x1) const;
    Rational operator*(Rational x1) const;
    Rational operator/(Rational x1) const;
    bool    operator==(Rational x)  const;

    int    IntValue()   const;
    double doubleValue() const;
    void   tostring();
    int    compareto(const Rational& obj);
    int    GCD();
};

#endif
