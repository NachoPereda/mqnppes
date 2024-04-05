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
            if (pictures[1].getMatrixElement(mask -1 ,i).first == "p(1)"){ // Si es P1 entonces x1 esta en la posicion siguiente
                result = result + pictures[7].getMatrixElement(mask -1 ,i).second * pictures[1].getMatrixElement(mask -1 ,i+1).second;
            }
            else // sino esta en la segunda posicion
                result = result + pictures[1].getMatrixElement(mask -1 ,i).second * pictures[1].getMatrixElement(mask -1 ,i+2).second;
            

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