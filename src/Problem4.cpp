#include <iostream>

#include "Problem4.h"

// A palindromic number reads the same both ways.The largest palindrome made from the product of two 2 - digit numbers is 9009 = 91 × 99.
// Find the largest palindrome made from the product of two 3 - digit numbers.

bool IsPalendrome(int Number)
{
	int digits[32];
	int numDigits = 0;
	for (;;)
	{
		int Product = Number / 10;
		int rem = Number - (Product * 10);
		digits[numDigits] = rem;
		numDigits++;
		if (0 == Product)
			break;
		Number = Product;
	}

	for (size_t i = 0; i < numDigits / 2; ++i)
	{
		if (digits[i] != digits[numDigits - i - 1])
		{
			return false;
		}
	}

	return true;
}

int LargestPalendrome()
{
	int largestPalendrome = 0;
	for (int i = 999; i > 1; --i)
	{
		for (int j = 999; j >= i; --j)
		{
			int product = i * j;
			if (product > largestPalendrome && IsPalendrome(product))
				largestPalendrome = product;
		}
	}

	return largestPalendrome;
}

void CProblem4::Execute()
{
	int solution = LargestPalendrome();
	std::cout << "Problem 4 Solution: " << solution << std::endl;
}
