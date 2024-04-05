/**
 * Project TFG Ignacio Pereda
 */

#include "Eval1.h"
#include <iostream>

/**
 * Eval1 implementation
 */

int Eval1::linearEvaluation()
{
    int result = 0;
    pictures[7].printMatrix();
    for (int i = 0; i < pictures[1].getColumns(); i++)
    {
        if (i%3==0)
        {
            result = result + pictures[7].getMatrixElement(mask -1 ,i).second * pictures[1].getMatrixElement(mask -1 ,i+1).second; // Pi * xi
            
        }
        
        
    }
    return result;
    
}

void Eval1::setMask()
{
    int numRows = pictures[0].getRows();
    mask = numRows - 2;
    std::cout << "Mask is "<<mask << std::endl;
}