#include <iostream>

#include "Problems.h"

//The sum of the squares of the first ten natural numbers is,
//	1^2 + 2^2 + ... + 10^2 = 385
//The square of the sum of the first ten natural numbers is,
//  (1 + 2 + ... + 10)^2 = 55^2 = 3025
// Hence the difference between the sum of the squares of the first ten natural numbersand the square of the sum is .
//  3025 - 385 = 2640
// Find the difference between the sum of the squares of the first one hundred natural numbersand the square of the sum.

void CProblem<6>::Execute()
{
	size_t sum = 0;
	size_t sum_squares = 0;
	// Do brute force
	for (size_t n = 1; n <= 100; ++n)
	{
		sum += n;
		sum_squares += n * n;
	}

	size_t diff = sum * sum - sum_squares;

	std::cout << "Problem 6 Solution: " << diff << std::endl;
}