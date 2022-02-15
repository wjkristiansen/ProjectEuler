#include <iostream>
#include <unordered_map>
#include "Problems.h"

// The following iterative sequence is defined for the set of positive integers:
//
// n → n/2 (n is even)
// n → 3n + 1 (n is odd)
//
// Using the rule above and starting with 13, we generate the following sequence:
//
// 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
// It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
//
// Which starting number, under one million, produces the longest chain?

std::unordered_map<size_t, size_t> CachedChainLengths;

static size_t Next(size_t n)
{
    if(n & 1) // odd
    {
        return 3 * n + 1;
    }

    // even
    return n / 2;
}

static size_t ChainLength(size_t n)
{
    if (n == 1)
        return 1;

    auto it = CachedChainLengths.find(n);
    if (it != CachedChainLengths.end())
        return it->second;

    size_t len = 1 + ChainLength(Next(n));
    CachedChainLengths.insert(std::make_pair(n, len));
    return len;
}

void CProblem<14>::Execute()
{
    size_t winner = 0;
    size_t maxLen = 1;

    for (size_t i = 2; i < 1000000; ++i)
    {
        auto len = ChainLength(i);
        if (len > maxLen)
        {
            maxLen = len;
            winner = i;
        }
    }

    std::cout << "Problem 14 Solution: " << winner << std::endl;
}