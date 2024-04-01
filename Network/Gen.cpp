#include <cmath>
#include <iostream>
#include "Gen.h"

std::vector<std::vector<int>> Gen::generateBinaryCombinations(int numBits)
{
    int numCombinations = std::pow(2, numBits);
    std::vector<std::vector<int>> truthTable(numCombinations, std::vector<int>(numBits, 0));

    for (int i = 0; i < numCombinations; ++i)
    {
        int value = i;
        for (int j = 0; j < numBits; ++j)
        {
            truthTable[i][j] = value % 2;
            value /= 2;
        }
    }

    for (const auto &row : truthTable)
    {
        for (int value : row)
        {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    return truthTable;
}

// std::vector<Picture> generateAllPictures(const Picture &originalPicture)
// {
//     std::vector<Picture> pictures;
//     Picture currentPicture = originalPicture.clone();
//     int numXLabels = 0;
//     numXLabels = originalPicture.getN();

//     const std::vector<std::vector<std::pair<std::string, int>>> &matrix = originalPicture.getMatrix(); // Acceder a la matriz

//     std::vector<std::vector<int>> combinations = generateBinaryCombinations(numXLabels);

//     for (const auto &combination : combinations)
//     {

//         currentPicture = originalPicture.clone();
//         for (int i = 0; i < int(matrix.size()); ++i)
//         {
//             for (int j = 0; j < int(matrix[i].size()); ++j)
//             {
//                 // Buscar las etiquetas "x"
//                 if (matrix[i][j].first[0] == 'x')
//                 {
//                     // Obtener el número después de la "x" en la etiqueta
//                     int xNumber = std::stoi(matrix[i][j].first.substr(1));
//                     // Usar este número para indexar la combinación
//                     currentPicture.setValue(i, j, combination[xNumber - 1]);
//                 }
//             }
//         }

//         pictures.push_back(currentPicture);
//     }

//     return pictures;
// }

std::vector<Picture> Gen::generateAllPictures(Picture &originalPicture)
{
    std::vector<Picture> pictures;
    Picture currentPicture = originalPicture.clone();
    int numRows = originalPicture.getRows();
    int numCols = originalPicture.getColumns();
    int numXLabels = originalPicture.getN();

    std::vector<std::vector<int>> combinations = generateBinaryCombinations(numXLabels);

    for (const auto &combination : combinations)
    {
        currentPicture = originalPicture.clone();
        for (int i = 0; i < numRows; ++i)
        {
            for (int j = 0; j < numCols; ++j)
            {
                // Buscar las etiquetas "x"
                if (currentPicture.getMatrixElement(i, j).first[0] == 'x')
                {
                    // Obtener el número después de la "x" en la etiqueta
                    int xNumber = std::stoi(currentPicture.getMatrixElement(i, j).first.substr(1));
                    // Usar este número para indexar la combinación
                    currentPicture.setValue(i, j, combination[xNumber - 1]);
                }
            }
        }
        pictures.push_back(currentPicture);
    }
    return pictures;
}