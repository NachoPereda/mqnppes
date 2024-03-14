#include "Picture.h"

class PictureGenerator {
public:
    static std::vector<Picture> generateCombinations(const Picture& basePicture) {
        std::vector<Picture> combinations;

        // Generar todas las combinaciones posibles de valores para las 'x'
        generateXCombinations(basePicture, combinations, 0);

        return combinations;
    }

private:
    static void generateXCombinations(const Picture& basePicture, std::vector<Picture>& combinations, int rowIndex) {
        if (rowIndex >= basePicture.matrix.size()) {
            combinations.push_back(basePicture.clone()); // Clonar la imagen base y agregarla a las combinaciones
            return;
        }

        // Clonar la imagen base
        Picture clonedPicture = basePicture.clone();

        for (int i = 0; i <= 1; ++i) {
            clonedPicture.matrix[rowIndex][1].second = i; // Establecer el valor de 'x' en 0 o 1

            // Llamar recursivamente para la siguiente fila
            generateXCombinations(clonedPicture, combinations, rowIndex + 1);
        }
    }
};
