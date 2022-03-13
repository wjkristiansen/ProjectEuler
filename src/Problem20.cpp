#include <iostream>
#include <vector>

#include "Util.h"
#include "Problems.h"


// n! means n x (n - 1) x ... x 3 x 2 x 1
//
// For example, 10! = 10 x 9 x ... x 3 x 2 x 1 = 3628800,
// and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
//
// Find the sum of the digits in the number 100!

void CProblem<20>::Execute()
{
    std::vector fact = ToDec(20922789888000); // start with 16!
    for (size_t n = 17; n <= 100; ++n)
    {
        fact = DecimalMultiply(fact, ToDec(n));
    }

    size_t sum = 0;
    for (char digit : fact)
    {
        sum += digit;
    }
    std::cout << "Problem 20 Solution: " << sum << std::endl;
} 