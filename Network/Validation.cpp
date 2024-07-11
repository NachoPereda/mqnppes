/**
 * Project TFG Ignacio Pereda
 */

#include "Validation.h"
#include <iostream>

/**
 * Validation implementation
 */

void Validation::validate(Picture picture)
{
    //TODO
    //XOR array linear --> result_linear
    //XOR array cuadratico --> result_quadratic
    //XOR result_linear y result_quadratic
    std::vector<std::pair<int, int>> p_elements = pictures[0].getPindex();
    std::regex pattern("^p");
    int result=0;
    int nfil = picture.getRows();
    int ncol = picture.getColumns();
    std::cout << "Evaluando XOR de:  " << std::endl;

    for (int i = 0; i < nfil; i++)
    {
        for (int j = 0; j < ncol; j++)
        {
            std::string res = picture.getMatrixElement(i, j).first;
            
            if(std::regex_search(res, pattern)){
                std::cout <<  picture.getMatrixElement(i, j).first << std::endl;
                result ^= picture.getMatrixElement(i, j).second;
            }
        }
        
    }
    std::cout << "Resultado Validacion:  " << result << std::endl;
    

    // for (auto& element : p_elements) {
    //     std::string res = pictures[7].getMatrixElement(element.first, element.second).first;
    //     if(std::regex_search(res, pattern)){
    //         std::cout << "Evaluando:  " << pictures[7].getMatrixElement(element.first, element.second).first << std::endl;
    //         result ^= pictures[7].getMatrixElement(element.first, element.second).second;
    //     }
    // }

    
}

void Validation::validateiterator()
{
    for (Picture& picture : pictures) {
        validate(picture);
    }

}