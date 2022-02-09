#include <iostream>

#include "Problems.h"
#include "PrimeNumbers.h"

// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 600851475143 ?
static size_t LargestPrimeFactor(size_t Number)
{
	for (size_t primeFactor : PrimeNumbers)
	{
		if (primeFactor > Number / 2)
			return Number;

		size_t factor = Number / primeFactor;
		if (factor * primeFactor == Number)
			return LargestPrimeFactor(factor);
	}

	return Number;
}

void CProblem<3>::Execute()
{
	std::cout << "Problem 3 Solution: " << LargestPrimeFactor(600851475143) << std::endl;
}
