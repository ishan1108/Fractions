//
// Created by ishan on 11-10-2019.
//

#ifndef MATHWORKS_FRACTION_H
#define MATHWORKS_FRACTION_H
#include <iostream>

class Fraction
{
public:
    Fraction();
    Fraction(int num, int deno);

    int getNumerator() const;
    void setNumerator(int numerator);

    int getDenominator() const;
    void setDenominator(int denominator);

    Fraction operator+(const Fraction& fraction) const;
    Fraction operator-(const Fraction& fraction) const;
    Fraction operator*(const Fraction& fraction) const;
    Fraction operator/(const Fraction& fraction) const;
    bool operator>(const Fraction& fraction) const;
    bool operator<(const Fraction& fraction) const;
    bool operator>=(const Fraction& fraction) const;
    bool operator<=(const Fraction& fraction) const;
    bool operator==(const Fraction& fraction) const;
    bool operator!=(const Fraction& fraction) const;

    friend std::ostream& operator<<(std::ostream& os, Fraction& fraction)
    {
        printOutput(os, fraction);
        return os;
    }

    ~Fraction();

private:
    int numerator;
    int denominator;

    int greatestCommonDivider(int x, int y) const ;
    int leastCommonMultiple(int& x, int& y) const;
    Fraction reduce(const Fraction& fraction) const;
    void isValidFraction(Fraction& f2) const;
    static void printOutput(std::ostream& os, const Fraction& fraction);
};


#endif //MATHWORKS_FRACTION_H
