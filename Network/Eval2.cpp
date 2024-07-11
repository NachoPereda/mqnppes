/**
 * Project TFG Ignacio Pereda
 */

#include "Eval2.h"
#include <iostream>

/**
 * Eval2 implementation
 */

void Eval2::quadraticEvaluation(Picture picture)
{
    int result = 0;
    std::cout << "Procesando Picture: " << std::endl;
    picture.printMatrix();
    int col = picture.getN() * 3; // Numero de columnas a recorrer
    for (int fil = 0; fil < mask; fil++)
    {
        for (int j = fil * 3; j < col-1;)
        {
            result = picture.getMatrixElement(fil, j).second * picture.getMatrixElement(fil, j + 1).second * picture.getMatrixElement(fil, j + 2).second;
            pictures[7].setValue(fil, j,result);
            std::cout << "Evaluando:  " <<picture.getMatrixElement(fil, j).first <<" * " <<picture.getMatrixElement(fil, j + 1).first << " * " <<picture.getMatrixElement(fil, j + 2).first << " = " << result<<std::endl;
            j = j +3; //Salto de 3 en 3 para evaluar Pij * xi * xj
        }
        
    }

}

void Eval2::quadraticEvaluationiterator()
{
    for (Picture& picture : pictures) {
        quadraticEvaluation(picture);
    }

}

void Eval2::setMask()
{
    int numRows = pictures[0].getRows();
    mask = numRows - 3;
    std::cout << "Mask is " << mask << std::endl;
}