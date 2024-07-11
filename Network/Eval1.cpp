/**
 * Project TFG Ignacio Pereda
 */

#include "Eval1.h"
#include <iostream>

/**
 * Eval1 implementation
 */

void Eval1::linearEvaluation(Picture picture)
{
    int result = 0;
    std::cout << "Procesando Picture: " << std::endl;
    picture.printMatrix();
    for (int i = 0; i < pictures[1].getColumns(); i++)
    {
        if (i%3==0)
        {
            result = picture.getMatrixElement(mask -1 ,i).second * picture.getMatrixElement(mask -1 ,i+1).second; // Pi * xi
            picture.setValue(mask -1 ,i,result);
            std::cout << "Evaluando: "<<picture.getMatrixElement(mask -1 ,i).first <<" * " <<picture.getMatrixElement(mask -1 ,i+1).first << " = " << result<< std::endl;
            
        }
        
        
    }
    
}

void Eval1::linearEvaluationiterator()
{
    for (Picture& picture : pictures) {
        linearEvaluation(picture);
    }


}

void Eval1::setMask()
{
    int numRows = pictures[0].getRows();
    mask = numRows - 2;
    std::cout << "Mask is "<<mask << std::endl;
}