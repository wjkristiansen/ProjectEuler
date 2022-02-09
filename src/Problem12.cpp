#include <iostream>

#include "Problems.h"

// The sequence of triangle numbers is generated by adding the natural numbers. So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The first ten terms would be:
//
// 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
//
// Let us list the factors of the first seven triangle numbers:
//
//  1: 1
//  3: 1,3
//  6: 1,2,3,6
// 10: 1,2,5,10
// 15: 1,3,5,15
// 21: 1,3,7,21
// 28: 1,2,4,7,14,28
// We can see that 28 is the first triangle number to have over five divisors.
//
// What is the value of the first triangle number to have over five hundred divisors?

size_t CountFactors(size_t Number)
{
    int Factors = 2; // At least 1 and Number are factors of Number

    for (int n = 2; n * n <= Number; ++n)
    {
        size_t m = (Number / n);
        if (Number == (m * n))
        {
            Factors += m == n ? 1 : 2;
        }
    }

    return Factors;
}

void CProblem<12>::Execute()
{
    size_t Triangle = 0;
    for (size_t Index = 1; ; Index++)
    {
        Triangle += Index;

        if (CountFactors(Triangle) > 500)
            break;
    }

    std::cout << "Problem 12 Solution: " << Triangle << std::endl;
}