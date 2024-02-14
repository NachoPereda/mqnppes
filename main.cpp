#include <iostream>
#include "Picture.h"

int main() {
    Picture picture;
    picture.readFromFile("matrix.txt");
    picture.printMatrix();

    // Cambiar el valor de un elemento
    picture.setValue(0, 0, 1);
    
    // Imprimir la matriz después de cambiar el valor
    std::cout << "" << std::endl;
    picture.printMatrix();

    return 0;
}