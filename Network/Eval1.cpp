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
    for (int i = 0; i < pictures[1].getColumns(); i++)
    {
        if (i%3!=2)
        {
            std::cout << pictures[1].getMatrixElement(mask -1 ,i).first << std::endl;
        }
        
        
    }
    
}

void Eval1::setMask()
{
    int numRows = pictures[0].getRows();
    mask = numRows - 2;
    std::cout << "Mask is "<<mask << std::endl;
}