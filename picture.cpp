#include "picture.h"
#include <iostream>

// Constructor por defecto
Picture::Picture() {}

// Constructor con parámetros para inicializar los coeficientes e indeterminadas
Picture::Picture(const std::vector<double>& coeffs, const std::vector<std::string>& indets) {
    coefficients = coeffs;
    indeterminates = indets;
}

// Función para establecer los coeficientes
void Picture::setCoefficients(const std::vector<double>& coeffs) {
    coefficients = coeffs;
}

// Función para obtener los coeficientes
std::vector<double> Picture::getCoefficients() const {
    return coefficients;
}

// Función para establecer las indeterminadas
void Picture::setIndeterminates(const std::vector<std::string>& indets) {
    indeterminates = indets;
}

// Función para obtener las indeterminadas
std::vector<std::string> Picture::getIndeterminates() const {
    return indeterminates;
}

// Función para imprimir la información de la imagen
void Picture::print() const {
    std::cout << "Coefficients: ";
    for (const auto& coeff : coefficients) {
        std::cout << coeff << " ";
    }
    std::cout << std::endl;

    std::cout << "Indeterminates: ";
    for (const auto& indet : indeterminates) {
        std::cout << indet << " ";
    }
    std::cout << std::endl;
}
