//
// Created by ishan on 11-10-2019.
//

#include "Fractions.h"

//-----------------------------------------------------------------------------//
// Constructor
//-----------------------------------------------------------------------------//

Fraction::Fraction() {}

Fraction::Fraction(int num, int deno)
{
    if(deno == 0)
    {
        std::cout << "Please enter a valid fraction" << std::endl;
        return;
    }
    setNumerator(num);
    setDenominator(deno);

}

Fraction::~Fraction()
{

}

//-----------------------------------------------------------------------------//
// Getters and Setters
//-----------------------------------------------------------------------------//

int Fraction::getNumerator() const
{
    return numerator;
}

void Fraction::setNumerator(int numerator)
{
    Fraction::numerator = numerator;
}

int Fraction::getDenominator() const
{
    return denominator;
}

void Fraction::setDenominator(int denominator)
{
    Fraction::denominator = denominator;
}

//-----------------------------------------------------------------------------//
// Operations
//-----------------------------------------------------------------------------//

Fraction Fraction::operator+(const Fraction& fraction) const
{
    Fraction result(getNumerator() * fraction.getDenominator()
                    + fraction.getNumerator()* getDenominator(),
                    getDenominator() * fraction.getDenominator());
    isValidFraction(result);
    result = reduce(result);
    return result;
}

Fraction Fraction::operator-(const Fraction& fraction) const
{
    Fraction result(getNumerator() * fraction.getDenominator()
                    - fraction.getNumerator()* getDenominator(),
                    getDenominator() * fraction.getDenominator());
    isValidFraction(result);
    result = reduce(result);
    return result;
}

Fraction Fraction::operator*(const Fraction& fraction) const
{
    Fraction result(getNumerator() * fraction.getNumerator(),
                    getDenominator() * fraction.getDenominator());
    isValidFraction(result);
    result = reduce(result);
    return result;
}

Fraction Fraction::operator/(const Fraction &fraction) const {
    Fraction result(getNumerator() * fraction.getDenominator(),
                    getDenominator() * fraction.getNumerator());
    isValidFraction(result);
    result = reduce(result);
    return result;
}

bool Fraction::operator>(const Fraction &fraction) const {
    int deno1 = getDenominator();
    int deno2 = fraction.getDenominator();
    int lcm = leastCommonMultiple(deno1, deno2);
    return this->getNumerator()*lcm > fraction.getNumerator()*lcm;
}

bool Fraction::operator<(const Fraction &fraction) const {
    int deno1 = getDenominator();
    int deno2 = fraction.getDenominator();
    int lcm = leastCommonMultiple(deno1, deno2);
    return this->getNumerator()*lcm < fraction.getNumerator()*lcm;
}

bool Fraction::operator>=(const Fraction &fraction) const {
    int deno1 = getDenominator();
    int deno2 = fraction.getDenominator();
    int lcm = leastCommonMultiple(deno1, deno2);
    return this->getNumerator()*lcm >= fraction.getNumerator()*lcm;
}

bool Fraction::operator<=(const Fraction &fraction) const {
    int deno1 = getDenominator();
    int deno2 = fraction.getDenominator();
    int lcm = leastCommonMultiple(deno1, deno2);
    return this->getNumerator()*lcm <= fraction.getNumerator()*lcm;
}

bool Fraction::operator==(const Fraction &fraction) const {
    int deno1 = getDenominator();
    int deno2 = fraction.getDenominator();
    int lcm = leastCommonMultiple(deno1, deno2);
    return this->getNumerator()*lcm == fraction.getNumerator()*lcm;
}

bool Fraction::operator!=(const Fraction &fraction) const {
    int deno1 = getDenominator();
    int deno2 = fraction.getDenominator();
    int lcm = leastCommonMultiple(deno1, deno2);
    return this->getNumerator()*lcm != fraction.getNumerator()*lcm;
}

//-----------------------------------------------------------------------------//
// Helper Functions
//-----------------------------------------------------------------------------//

int Fraction::greatestCommonDivider(int x, int y) const
{
    if(x==0)
        return y;
    return greatestCommonDivider(y % x, x);
}

int Fraction::leastCommonMultiple(int& x, int& y) const
{
    return (x * y) / greatestCommonDivider(x, y);
}

Fraction Fraction::reduce(const Fraction& fraction) const
{
    int num = fraction.getNumerator();
    int deno = fraction.getDenominator();
    int gcd = greatestCommonDivider(num, deno);
    if(gcd == 1)
        return Fraction(num, deno);
    return reduce(Fraction(num/gcd, deno/gcd));
}

void Fraction::isValidFraction(Fraction &f2) const
{
    if(getDenominator() == 0 || f2.getDenominator() == 0)
    {
        std::cout << "Invalid Fraction" << std::endl;
        exit(-1);
    }
}

void Fraction::printOutput(std::ostream &os, const Fraction &fraction)
{
    if(fraction.getNumerator() == 0)
        os << 0 ;
    else if(fraction.getDenominator() == 1)
        os << fraction.getNumerator();
    else if(fraction.getDenominator() == -1)
        os << -(fraction.getNumerator());
    else if(fraction.getNumerator() < 0 && fraction.getDenominator() > 0)
        os << "-(" << -(fraction.getNumerator()) << "/" << fraction.getDenominator() << ")";
    else if(fraction.getDenominator() < 0 && fraction.getNumerator() > 0)
        os << "-(" << fraction.getNumerator() << "/" << -(fraction.getDenominator()) << ")";
    else if(fraction.getNumerator() < 0 && fraction.getDenominator() < 0)
        os << -(fraction.getNumerator()) << "/" << -(fraction.getDenominator());
    else
        os << fraction.getNumerator() << "/" << fraction.getDenominator();
}
