/**
 * Project TFG Ignacio Pereda
 */

#include "Eval2.h"
#include <iostream>

/**
 * Eval2 implementation
 */

int Eval2::quadraticEvaluation()
{
    int result = 0;
    std::cout << "Procesando Picture: " << std::endl;
    pictures[7].printMatrix();
    int col = pictures[7].getN() * 3; // Numero de columnas a recorrer
    for (int fil = 0; fil < mask; fil++)
    {
        for (int j = fil * 3; j < col-1;)
        {
            result = pictures[7].getMatrixElement(fil, j).second * pictures[1].getMatrixElement(fil, j + 1).second * pictures[1].getMatrixElement(fil, j + 2).second;
            pictures[7].setValue(fil, j,result);
            std::cout << "Evaluando:  " <<pictures[7].getMatrixElement(fil, j).first <<" * " <<pictures[1].getMatrixElement(fil, j + 1).first << " * " <<pictures[1].getMatrixElement(fil, j + 2).first << " = " << result<<std::endl;
            j = j +3; //Salto de 3 en 3 para evaluar Pij * xi * xj
        }
        
    }

    return result;
}

void Eval2::setMask()
{
    int numRows = pictures[0].getRows();
    mask = numRows - 3;
    std::cout << "Mask is " << mask << std::endl;
}