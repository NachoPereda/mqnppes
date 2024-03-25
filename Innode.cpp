#include "Innode.h"

void Innode::capa() {
    // Asegúrate de que mask no sea mayor que el número de filas de la imagen
    int numRows = picture.getNumRows();
    int maxRow = std::min(mask, numRows);

    // Calcular la suma de las filas hasta la fila mask
    for (int i = 0; i < maxRow; ++i) {
        int sumRow = 0;
        for (const auto& pair : picture.getRow(i)) {
            sumRow += pair.second;
        }
        std::cout << "Suma de la fila " << i << ": " << sumRow << std::endl;
    }

    // Calcular la suma de las columnas
    for (int j = 0; j < picture.getNumCols(); ++j) {
        int sumCol = 0;
        for (int i = 0; i < numRows; ++i) {
            if (i < maxRow) {
                sumCol += picture.getValue(i, j);
            }
        }
        std::cout << "Suma de la columna " << j << ": " << sumCol << std::endl;
    }
}
