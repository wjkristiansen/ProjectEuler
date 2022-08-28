#include <iostream>
#include <set>

#include "Util.h"
#include "Problems.h"


// Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
// If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

// For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

// Evaluate the sum of all the amicable numbers under 10000.

int constexpr SumFactors(int n)
{
    int sum = 1;
    for(int v = n/2; v > 1; --v)
    {
        if((n / v) * v == n)
        {
            sum += v;
        }
    }

    return sum;
}

void CProblem<21>::Execute()
{
    std::set<int> filter;
    int sumAmicable = 0;
    for (int n = 1; n < 10000; ++n)
    {
        if (filter.find(n) == filter.end())
        {
            int sumPropDiv1 = SumFactors(n);
            int sumPropDiv2 = SumFactors(sumPropDiv1);

            if (sumPropDiv2 == n && sumPropDiv2 != sumPropDiv1)
            {
                sumAmicable += n + sumPropDiv1;
                filter.insert(sumPropDiv1);
            }
        }
    }

    std::cout << sumAmicable << std::endl;
} 