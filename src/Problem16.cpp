#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "Util.h"
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