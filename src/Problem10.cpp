#include <iostream>
#include "PrimeNumbers.h"
#include "Problems.h"

//The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
//Find the sum of all the primes below two million.

void CProblem<10>::Execute()
{
    size_t sum = 2;
    for (int number = 3; number < 2000000; number += 2)
    {
        if (IsPrime(number))
        {
            sum += number;
        }
    }

    std::cout << "Problem 10 Solution: " << sum << std::endl;
}