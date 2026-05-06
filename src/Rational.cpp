#include "Rational.h"
#include <iostream>
using namespace std;

int Rational::gcd(int a, int b)
{
    if (a == 0 || b == 0) return 0;
    else if (a == b)      return a;
    else if (a > b)       return gcd(a - b, b);
    else                  return gcd(a, b - a);
}

Rational::Rational()
{
    numerator   = 0;
    denominator = 1;
}

Rational::Rational(int x1, int x2)
{
    numerator   = x1;
    denominator = x2;
}

int Rational::getnumerator()   { return numerator; }
int Rational::getdenominator() { return denominator; }

int Rational::setNumerator(int n)   { numerator   = n; return numerator; }
int Rational::setDenominator(int d) { denominator = d; return denominator; }

Rational Rational::operator+(Rational n1) const
{
    Rational n2;
    n2.numerator   = (numerator * n1.denominator) + (n1.numerator * denominator);
    n2.denominator = (denominator * n1.denominator);
    return n2;
}

Rational Rational::operator-(Rational x1) const
{
    Rational x2;
    x2.numerator   = (numerator * x1.denominator) - (x1.numerator * denominator);
    x2.denominator = (denominator * x1.denominator);
    return x2;
}

Rational Rational::operator*(Rational x1) const
{
    Rational x2;
    x2.numerator   = numerator   * x1.numerator;
    x2.denominator = denominator * x1.denominator;
    return x2;
}

Rational Rational::operator/(Rational x1) const
{
    Rational x2;
    x2.numerator   = numerator   * x1.denominator;
    x2.denominator = denominator * x1.numerator;   // fixed: was x1.denominator
    return x2;
}

bool Rational::operator==(Rational x) const
{
    return (numerator == x.numerator && denominator == x.denominator);
}

int Rational::IntValue() const
{
    return (numerator / denominator);
}

double Rational::doubleValue() const
{
    return (double)numerator / (double)denominator;
}

void Rational::tostring()
{
    if (denominator == 1)
        cout << numerator;
    else
        cout << numerator << "/" << denominator;
}

int Rational::compareto(const Rational& obj)
{
    double val      = (double)numerator   / denominator;
    double otherVal = (double)obj.numerator / obj.denominator;
    if (val > otherVal)  return  1;
    if (val == otherVal) return  0;
    return -1;
}

int Rational::GCD()
{
    return gcd(numerator, denominator);
}
