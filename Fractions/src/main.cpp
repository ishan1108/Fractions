#include "Fractions.h"

int main()
{
    Fraction fraction(-20,-10);
    Fraction fraction1(1,2);
    Fraction add = fraction + fraction1;
    Fraction sub = fraction - fraction1;
    Fraction mul = fraction * fraction1;
    if(fraction > fraction1)
        std::cout << fraction << std::endl;
    else
        std::cout << fraction1 << std::endl;
    std::cout << add << std:: endl;
    std::cout << sub << std:: endl;
    std::cout << mul << std:: endl;
    return 0;
}