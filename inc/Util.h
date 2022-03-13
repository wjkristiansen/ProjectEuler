#pragma once

#include <vector>
#include <string>
#include <sstream>

// Multiplies two numbers represented as an array of decimal digits 0-9 with the least significant digit at index [0]
inline std::vector<char> DecimalMultiply(const std::vector<char> &v1, const std::vector<char> &v2)
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

// Converts the number `n` to an array of decimal digits 0-9 with the least significant digit at index [0]
inline std::vector<char> ToDec(size_t n)
{
    std::ostringstream os;
    os << n;
    std::string s = os.str();
    std::vector<char> v(s.rbegin(), s.rend());

    // convert from ascii to number
    for (auto& digit : v)
    {
        digit -= '0';
    }

    return v;
}

