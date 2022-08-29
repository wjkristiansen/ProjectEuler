#include <iostream>
#include <unordered_map>

#include "Util.h"
#include "Problems.h"

// A perfect number is a number for which the sum of its proper divisors is exactly equal to the number.
// For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

// A number n is called deficient if the sum of its proper divisors is less than n and it is called
// abundant if this sum exceeds n.

// As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written
// as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers
// greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot
// be reduced any further by analysis even though it is known that the greatest number that cannot be
// expressed as the sum of two abundant numbers is less than this limit.

// Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.

std::unordered_map<size_t, bool> KnownNumbers;

class AddAccumulator
{
public:
    size_t Sum = 0;
    void Accumulate(size_t n) { Sum += n; }
};

inline bool IsAbundant(size_t n)
{
    auto it = KnownNumbers.find(n);
    if ( it != KnownNumbers.end())
        return it->second;

    AddAccumulator acc;
    AccumulateProperDivisors(n, acc);
    bool result = acc.Sum > n;

    KnownNumbers.emplace(n, result);

    return result;
}

void CProblem<23>::Execute()
{
    size_t Sum = 0;
    for (size_t v = 28123; v > 0; --v)
    {
        size_t left = v / 2;
        for (; left > 0; --left)
        {
            size_t right = v - left;
            if (IsAbundant(left) && IsAbundant(right))
            {
                // v can be written as the sum of two abundant numbers
                break;
            }
        }

        if (left == 0)
        {
            Sum += v;
        }
    }

    std::cout << Sum << std::endl;
}