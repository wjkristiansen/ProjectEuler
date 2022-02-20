#include <iostream>
#include "Problems.h"

// Starting in the top left corner of a 2 x 2 grid, and only being able to
// move to the right and down, there are exactly 6 routes to the bottom right corner.
//
//  . _ . _ .        . _ .   .        . _ .   .
//          |            |                |    
//  .   .   .        .   . _ .        .   .   .
//          |                |            |    
//  .   .   .        .   .   .        .   . _ .
//  
//  .   .   .        .   .   .        .   .   .
//  |                |                |        
//  . _ . _ .        . _ .   .        .   .   .
//          |            |            |        
//  .   .   .        .   . _ .        . _ . _ .
//
// How many such routes are there through a 20 x 20 grid ?

static const size_t GridSize = 20;

static size_t CountPaths()
{
    static size_t NumPaths[GridSize + 1][GridSize + 1];

    for (size_t row = GridSize; row != size_t(~0); --row)
    {
        for (size_t col = GridSize; col != size_t(~0); --col)
        {
            if (row == GridSize || col == GridSize)
                NumPaths[row][col] = 1;
            else
                NumPaths[row][col] = NumPaths[row + 1][col] + NumPaths[row][col + 1];
        }
    }
    return NumPaths[0][0];
}

void CProblem<15>::Execute()
{
    size_t NumPaths = CountPaths();

    std::cout << "Problem 15 Solution: " << NumPaths << std::endl;
}