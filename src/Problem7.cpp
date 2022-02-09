#include <iostream>

#include "PrimeNumbers.h"
#include "Problems.h"

// By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
// What is the 10001 st prime number?

void CProblem<7>::Execute()
{
    int PrimeCount = 1;
    int number = 3;
    for( ; PrimeCount < 10001; number += 2)
    {
        if (IsPrime(number))
        {
            PrimeCount++;
        }
    }

    number -= 2;

	std::cout << "Problem 7 Solution: " << number << std::endl;
}