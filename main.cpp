#include "picture.h" // Incluimos la definición de la clase Picture

int main() {
    // Crear varios objetos Picture
    std::vector<double> coeffs1 = {1.5, 2.7, -3.2};
    std::vector<std::string> indets1 = {"x", "y", "z"};
    Picture pic1(coeffs1, indets1);

    std::vector<double> coeffs2 = {0.8, -2.1, 4.3};
    std::vector<std::string> indets2 = {"a", "b", "c"};
    Picture pic2(coeffs2, indets2);

    // Imprimir la información de los objetos Picture
    pic1.print();
    pic2.print();

    return 0;
}
