#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "Problems.h"


// 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
// What is the sum of the digits of the number 2^1000?

// = 2*(40 * 25)
// = (2^40)^25
// = 2^40 * 2^40 * 2^40 * 2^40 * 2^40
//    * 2^40 * 2^40 * 2^40 * 2^40 * 2^40
//    * 2^40 * 2^40 * 2^40 * 2^40 * 2^40
//    * 2^40 * 2^40 * 2^40 * 2^40 * 2^40
//    * 2^40 * 2^40 * 2^40 * 2^40 * 2^40

std::vector<char> DecimalMultiply(const std::vector<char> &v1, const std::vector<char> &v2)
{
    std::vector<char> acc(v1.size() + v2.size(), 0);
    int accOffset = 0;
    for (auto it2 = v2.begin(); it2 != v2.end(); ++it2)
    {
        char mulCarry = 0;
        char addCarry = 0;
        int accIndex = 0;

        for (auto it1 = v1.begin(); it1 != v1.end(); ++it1)
        {
            char v = *it1 * *it2 + mulCarry;
            mulCarry = v / 10;
            char sum = acc[accIndex + accOffset] + (v % 10) + addCarry;
            acc[accIndex + accOffset] = sum % 10;
            addCarry = sum / 10;
            accIndex++;
        }
        acc[accIndex + accOffset] = mulCarry + addCarry;
        accOffset++;
    }

    return acc;
}

const size_t Pow40 = size_t(1ull << 40);

void CProblem<16>::Execute()
{
    std::ostringstream pow40SStream;
    pow40SStream << Pow40;
    auto pow40String = pow40SStream.str();
    std::vector<char> pow40Digits(pow40String.rbegin(), pow40String.rend());

    // Convert pow40Digits from ascii to number
    for (auto it = pow40Digits.begin(); it != pow40Digits.end(); ++it)
        *it -= '0';

    std::vector<char> digits = pow40Digits;

    // Perform 24 DecimalMultiply operations with 2^40
    for (int i = 0; i < 24; ++i)
    {
        digits = DecimalMultiply(pow40Digits, digits);
    }

    size_t sum = 0;
    for (auto it = digits.begin(); it != digits.end(); ++it)
        sum += *it;

    std::cout << "Problem 16 Solution: " << sum << std::endl;
}