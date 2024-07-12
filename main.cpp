#include <iostream>
#include "Picture.h"
// #include "Network/Network.h"
#include "Network/Gen.h"
#include "Network/Eval1.h"
#include <cmath>
#include "Network/Eval2.h"
#include "Network/Validation.h"

// std::vector<std::vector<int>> generateBinaryCombinations(int numBits) {
//     int numCombinations = std::pow(2, numBits);
//     std::vector<std::vector<int>> truthTable(numCombinations, std::vector<int>(numBits, 0));
    
//     for (int i = 0; i < numCombinations; ++i) {
//         int value = i;
//         for (int j = 0; j < numBits; ++j) {
//             truthTable[i][j] = value % 2;
//             value /= 2;
//         }
//     }

//     for (const auto& row : truthTable) {
//         for (int value : row) {
//             std::cout << value << " ";
//         }
//         std::cout << std::endl;
//     }
    
//     return truthTable;
// }

// std::vector<Picture> generateAllPictures(const Picture& originalPicture) {
//     std::vector<Picture> pictures;
//     Picture currentPicture = originalPicture.clone();
//     int numXLabels = 0;
//     numXLabels = originalPicture.getN();
    
//     const std::vector<std::vector<std::pair<std::string, int>>>& matrix = originalPicture.getMatrix(); // Acceder a la matriz
    
//     std::vector<std::vector<int>> combinations = generateBinaryCombinations(numXLabels);
    
//     for (const auto& combination : combinations) {
        
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

int main(int argc, char* argv[]) {
    // Verifica que se hayan pasado los argumentos necesarios
    if (argc < 3) {
        std::cerr << "Uso: " << argv[0] << " <fichero_matrix> <fichero_coef>" << std::endl;
        return 1;
    }

    // Asigna los nombres de los ficheros a variables
    std::string matrixFile = argv[1];
    std::string coefFile = argv[2];
    Picture picture;
    // picture.readFromFile("matrix.txt");
    // picture.assignCoefficients("coef.txt");
    picture.readFromFile(matrixFile);
    picture.assignCoefficients(coefFile);
    picture.printMatrix();

    // Cambiar el valor de un elemento
    //picture.setValue(0, 0, 1);
    
    // Imprimir la matriz después de cambiar el valor
    //std::cout << "" << std::endl;
    //picture.printMatrix();

    std::cout << "Gen working: " << std::endl;

    Gen gen;

    // Generar todas las Pictures con combinaciones de valores para las etiquetas "x"
    std::vector<Picture> allPictures = gen.generateAllPictures(picture);
    
    // Imprimir todas las Pictures generadas
    for (int i = 0; i < int(allPictures.size()); ++i) {
        std::cout << "Picture " << i+1 << ":\n";
        allPictures[i].printMatrix();
        std::cout << std::endl;
    }
    
    Eval1 eval;
    eval.SetPictures(allPictures);
    eval.setMask();
    std::cout << "---------------------------------------------------------------------------" <<std::endl;
    std::cout << "Linear result:  " <<std::endl;
    eval.linearEvaluationiterator();
    std::cout << "---------------------------------------------------------------------------" <<std::endl;
    Eval2 quadeval;
    quadeval.SetPictures(allPictures);
    quadeval.setMask();
    std::cout << "Quadratic result:   " <<std::endl;
    quadeval.quadraticEvaluationiterator();
    std::cout << "---------------------------------------------------------------------------" <<std::endl;

    Validation val;
    val.SetPictures(allPictures);
    val.validateiterator();


    return 0;
}