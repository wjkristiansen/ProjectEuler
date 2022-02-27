#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <assert.h>

#include "Problems.h"

static std::string ToString(int Number)
{
    std::string numberString;

    assert(Number > 0 && Number <= 1000);

    if(Number == 1000)
        return "OneThousand";

    switch(Number / 100)
    {
    case 9:
        numberString += "NineHundred";
        break;
    case 8:
        numberString += "EightHundred";
        break;
    case 7:
        numberString += "SevenHundred";
        break;
    case 6:
        numberString += "SixHundred";
        break;
    case 5:
        numberString += "FiveHundred";
        break;
    case 4:
        numberString += "FourHundred";
        break;
    case 3:
        numberString += "ThreeHundred";
        break;
    case 2:
        numberString += "TwoHundred";
        break;
    case 1:
        numberString += "OneHundred";
        break;
    case 0:
        break;
    }

    bool UsesAnd = Number > 100;

    Number = Number % 100;

    // Stop if even hundred
    if(Number == 0)
        return numberString;

    if(UsesAnd)
        numberString += "And";

    switch(Number / 10)
    {
    case 9:
        numberString += "Ninety";
        break;
    case 8:
        numberString += "Eighty";
        break;
    case 7:
        numberString += "Seventy";
        break;
    case 6:
        numberString += "Sixty";
        break;
    case 5:
        numberString += "Fifty";
        break;
    case 4:
        numberString += "Forty";
        break;
    case 3:
        numberString += "Thirty";
        break;
    case 2:
        numberString += "Twenty";
        break;
    }

    if (Number >= 20)
    {
        Number = Number % 10;
        if (Number == 0)
            return numberString;
    }
    else
    {
        // Handle One through Ninteen
        Number = Number % 20;
    }

    switch(Number)
    {
    case 19:
        numberString += "Nineteen";
        break;
    case 18:
        numberString += "Eighteen";
        break;
    case 17:
        numberString += "Seventeen";
        break;
    case 16:
        numberString += "Sixteen";
        break;
    case 15:
        numberString += "Fifteen";
        break;
    case 14:
        numberString += "Fourteen";
        break;
    case 13:
        numberString += "Thirteen";
        break;
    case 12:
        numberString += "Twelve";
        break;
    case 11:
        numberString += "Eleven";
        break;
    case 10:
        numberString += "Ten";
        break;
    case 9:
        numberString += "Nine";
        break;
    case 8:
        numberString += "Eight";
        break;
    case 7:
        numberString += "Seven";
        break;
    case 6:
        numberString += "Six";
        break;
    case 5:
        numberString += "Five";
        break;
    case 4:
        numberString += "Four";
        break;
    case 3:
        numberString += "Three";
        break;
    case 2:
        numberString += "Two";
        break;
    case 1:
        numberString += "One";
        break;
    }

    return numberString;
}

void CProblem<17>::Execute()
{
    int letterCount = 0;
    for(int i = 1; i <= 1000; ++i)
    {
        std::string numberString = ToString(i);
        letterCount += int(numberString.length());
        std::cout << numberString << std::endl;
    }

    std::cout << "Problem 17 Solution: " << letterCount << std::endl;
}