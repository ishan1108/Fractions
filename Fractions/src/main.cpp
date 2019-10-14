#include "Fractions.h"
#include <assert.h>

void Test()
{
    Fraction a(10, 20);
    Fraction b(20, 30);
    Fraction c(30, 40);
    Fraction d(40, 50);
    Fraction e(50, 60);

    Fraction add = a + b;
    Fraction sub = b - c;
    Fraction mul = c * d;
    Fraction div = d / e;
    Fraction addi = a + 2;
    Fraction subi = a - 2;
    Fraction muli = a * 2;
    Fraction divi = div / 2;

    assert(add == Fraction(7,6));
    assert(sub == Fraction(-1,12));
    assert(mul == Fraction(3,5));
    assert(div == Fraction(24,25));
    assert(add > sub);
    assert(mul != sub);
    assert(mul < div);
    assert(add >= Fraction(7,6));
    assert(add <= Fraction(7,6));
    assert(addi == Fraction(5,2));
    assert(subi <= Fraction(-5,6));
    assert(muli <= Fraction(14,6));
    assert(divi <= Fraction(12,25));

    std::cout << "The Fractions created are as follows" << std::endl;
    std::cout << "Addition of a & b is " << add << std::endl;
    std::cout << "Subtraction of b & c is " << sub << std::endl;
    std::cout << "Multiplication of c & d is " << mul << std::endl;
    std::cout << "Division of d & e is " << div << std::endl;
    std::cout << "All the assertion passed" << std::endl;
}


int main()
{
    // Tests the methods
    Test();
    return 0;
}