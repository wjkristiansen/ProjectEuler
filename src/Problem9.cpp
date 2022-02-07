#include <iostream>
#include "Problem9.h"

// A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
//
//  a^2 + b^2 = c^2
//
// For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
//
// There exists exactly one Pythagorean triplet for which a + b + c = 1000.
// Find the product abc.

// This solution applies Euclid's formula to calculate Pythagorean triples
// For any arbitrary pair of values m and n
// a = m^2 - n^2, b = 2*m*n, c = m^2 + n^2

void Euclid(size_t m, size_t n, size_t&a, size_t&b, size_t&c)
{
    a = m * m - n * n;
    b = 2 * m * n;
    c = m * m + n * n;
}

void CProblem9::Execute()
{
    size_t m = 1;
    size_t n = 1;
    size_t a, b, c;

    for(n = 1;;++n)
    {
        if (n * n > 1000)
            break; // Already too big

        for(m = n + 1;;++m)
        {
            Euclid(m, n, a, b, c);
            size_t sum = a + b + c;
            if(1000 == a + b + c)
                goto done;

            if(sum > 1000)
                break;
        }
    }

    std::cout << "No solution" << std::endl;

    return;

done:
    std::cout << "Problem 9 Solution: " << a * b * c << std::endl;
    std::cout << "a=" << a << std::endl;
    std::cout << "b=" << b << std::endl;
    std::cout << "c=" << c << std::endl;
}