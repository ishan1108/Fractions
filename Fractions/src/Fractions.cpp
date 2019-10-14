//
// Created by ishan on 11-10-2019.
//

#include "Fractions.h"

//-----------------------------------------------------------------------//
// Constructor
//-----------------------------------------------------------------------//

// Default Constructor
Fraction::Fraction() {}

// Constructor with numerator and denominator
Fraction::Fraction(int num, int deno)
{
    if(deno == 0)
    {
        std::cout << "Please enter a valid fraction" << std::endl;
        return;
    }
    // If denominator is less than zero, set the numerator as negative
    // and denominator as positive.
    if(deno < 0)
    {
        setNumerator(-num);
        setDenominator(-deno);
    }
    else
    {
        setNumerator(num);
        setDenominator(deno);
    }

}

// Default destructor
Fraction::~Fraction()
{

}

//-----------------------------------------------------------------------//
// Getters and Setters
//-----------------------------------------------------------------------//

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

//-----------------------------------------------------------------------//
// Operations
//-----------------------------------------------------------------------//

//Addition---------------------------------------------------------------//
Fraction Fraction::operator+(const Fraction& fraction) const
{
    Fraction result(getNumerator() * fraction.getDenominator()
                    + fraction.getNumerator()* getDenominator(),
                    getDenominator() * fraction.getDenominator());
    result = setFraction(result);
    return result;
}

Fraction Fraction::operator+(const int &x) const
{
    Fraction temp(x,1);
    return *this + temp;
}

Fraction Fraction::operator+=(const Fraction &fraction)
{
    *this = *this + fraction;
    return *this;
}

//Subtraction------------------------------------------------------------//
Fraction Fraction::operator-(const Fraction& fraction) const
{
    Fraction result(getNumerator() * fraction.getDenominator()
                    - fraction.getNumerator()* getDenominator(),
                    getDenominator() * fraction.getDenominator());
    result = setFraction(result);
    return result;
}

Fraction Fraction::operator-(const int &x) const
{
    Fraction temp(x,1);
    return *this - temp;
}

Fraction Fraction::operator-=(const Fraction &fraction)
{
    *this = *this - fraction;
    return *this;
}

//Multiplication----------------------------------------------------------//
Fraction Fraction::operator*(const Fraction& fraction) const
{
    Fraction result(getNumerator() * fraction.getNumerator(),
                    getDenominator() * fraction.getDenominator());
    result = setFraction(result);
    return result;
}

Fraction Fraction::operator*(const int &x) const
{
    Fraction temp(x,1);
    return *this * temp;
}

Fraction Fraction::operator*=(const Fraction &fraction)
{
    *this = *this * fraction;
    return *this;
}

//Division----------------------------------------------------------------//
Fraction Fraction::operator/(const Fraction &fraction) const
{
    Fraction result(getNumerator() * fraction.getDenominator(),
                    getDenominator() * fraction.getNumerator());
    result = setFraction(result);
    return result;
}

Fraction Fraction::operator/(const int &x) const {
    Fraction temp(x,1);
    return *this / temp;
}

Fraction Fraction::operator/=(const Fraction &fraction)
{
    *this = *this / fraction;
    return *this;
}

//Equality----------------------------------------------------------------//
bool Fraction::operator>(const Fraction &fraction) const
{
    int deno1 = getDenominator();
    int deno2 = fraction.getDenominator();
    int lcm = leastCommonMultiple(deno1, deno2);
    Fraction left = setFraction(const_cast<Fraction &>(*this));
    Fraction right = setFraction(const_cast<Fraction &>(fraction));
    return left.getNumerator()*(lcm/left.getDenominator()) >
            right.getNumerator()*(lcm/right.getDenominator());
}

bool Fraction::operator<(const Fraction &fraction) const
{
    int deno1 = getDenominator();
    int deno2 = fraction.getDenominator();
    int lcm = leastCommonMultiple(deno1, deno2);
    Fraction left = setFraction(const_cast<Fraction &>(*this));
    Fraction right = setFraction(const_cast<Fraction &>(fraction));
    return left.getNumerator()*(lcm/left.getDenominator()) <
           right.getNumerator()*(lcm/right.getDenominator());
}

bool Fraction::operator>=(const Fraction &fraction) const
{
    int deno1 = getDenominator();
    int deno2 = fraction.getDenominator();
    int lcm = leastCommonMultiple(deno1, deno2);
    Fraction left = setFraction(const_cast<Fraction &>(*this));
    Fraction right = setFraction(const_cast<Fraction &>(fraction));
    return left.getNumerator()*(lcm/left.getDenominator()) >=
           right.getNumerator()*(lcm/right.getDenominator());
}

bool Fraction::operator<=(const Fraction &fraction) const
{
    int deno1 = getDenominator();
    int deno2 = fraction.getDenominator();
    int lcm = leastCommonMultiple(deno1, deno2);
    Fraction left = setFraction(const_cast<Fraction &>(*this));
    Fraction right = setFraction(const_cast<Fraction &>(fraction));
    return left.getNumerator()*(lcm/left.getDenominator()) <=
           right.getNumerator()*(lcm/right.getDenominator());
}

bool Fraction::operator==(const Fraction &fraction) const
{
    int deno1 = getDenominator();
    int deno2 = fraction.getDenominator();
    int lcm = leastCommonMultiple(deno1, deno2);
    Fraction left = setFraction(const_cast<Fraction &>(*this));
    Fraction right = setFraction(const_cast<Fraction &>(fraction));
    return left.getNumerator()*(lcm/left.getDenominator()) ==
           right.getNumerator()*(lcm/right.getDenominator());
}

bool Fraction::operator!=(const Fraction &fraction) const
{
    int deno1 = getDenominator();
    int deno2 = fraction.getDenominator();
    int lcm = leastCommonMultiple(deno1, deno2);
    Fraction left = setFraction(const_cast<Fraction &>(*this));
    Fraction right = setFraction(const_cast<Fraction &>(fraction));
    return left.getNumerator()*(lcm/left.getDenominator()) !=
           right.getNumerator()*(lcm/right.getDenominator());
}

//-----------------------------------------------------------------------//
// Private Helper Functions
//-----------------------------------------------------------------------//

Fraction Fraction::reduce(const Fraction& fraction) const
{
    int num = fraction.getNumerator();
    int deno = fraction.getDenominator();
    int gcd = greatestCommonDivider(num, deno);
    if(gcd == 1)
        return Fraction(num, deno);
    return reduce(Fraction(num/gcd, deno/gcd));
}

Fraction Fraction::setFraction(Fraction &fraction) const
{
    if(getDenominator() == 0 || fraction.getDenominator() == 0)
    {
        std::cout << "Invalid Fraction" << std::endl;
        exit(-1);
    }
    if(getDenominator() < 0)
    {
        return reduce(Fraction(-fraction.getNumerator(), -fraction.getDenominator()));
    }
    return reduce(Fraction(-fraction.getNumerator(), -fraction.getDenominator()));
}

int Fraction::leastCommonMultiple(int& x, int& y) const
{
    return (x * y) / greatestCommonDivider(x, y);
}

int Fraction::greatestCommonDivider(int x, int y) const
{
    if(x < 0) x = -x;
    if(y < 0) y = -y;
    if(x==0)
        return y;
    return greatestCommonDivider(y % x, x);
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

//-----------------------------------------------------------------------//