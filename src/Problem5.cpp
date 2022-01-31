#include <iostream>

#include "Problem5.h"

// 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20 ?

static int LeastCommonMultiple(int a, int b)
{
    int max = a * b;
    for (int i = b; i < max; i += b)
    {
        if (0 == (i % a))
        {
            return i;
        }
    }
    return max;
}

static int RangeLeastCommonMultiple(int min, int max)
{
    int a = min;
    int b = a + 1;
    int multiple = a * b;

    for (int i = b + 1; i <= max; ++i)
    {
        multiple = LeastCommonMultiple(i, multiple);
    }

    return multiple;
}

void CProblem5::Execute()
{
    int solution = RangeLeastCommonMultiple(2, 20);

    std::cout << "Solution: " << solution << std::endl;
}