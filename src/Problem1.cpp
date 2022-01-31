#include <iostream>

#include "Problem1.h"

// Problem:
// If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
// Find the sum of all the multiples of 3 or 5 below 1000.

void CProblem1::Execute()
{
    int sum = 0;

    // Multiples of 3
    for(int i = 3; i < 1000; i += 3)
    {
        sum += i;
    }

    // Multiples of 5
    for(int i = 5; i < 1000; i += 5)
    {
        // Exclude multiples of 3 as they were already counted
        if(0 != (i % 3))
            sum += i;
    }

    std::cout << "Solution: " << sum << std::endl;
}
