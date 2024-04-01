/**
 * Project TFG Ignacio Pereda
 */

#include "Eval1.h"
#include <iostream>

/**
 * Eval1 implementation
 */

void Eval1::linearEvaluation()
{
}

void Eval1::setMask()
{
    int numRows = pictures[0].getRows();
    mask = numRows - 2;
    std::cout << mask << std::endl;
}