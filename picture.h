#ifndef PICTURE_H
#define PICTURE_H

#include <vector>
#include <string>

class Picture {
private:
    std::vector<double> coefficients;
    std::vector<std::string> indeterminates;

public:
    // Constructor por defecto
    Picture();

    // Constructor con parámetros para inicializar los coeficientes e indeterminadas
    Picture(const std::vector<double>& coeffs, const std::vector<std::string>& indets);

    // Función para establecer los coeficientes
    void setCoefficients(const std::vector<double>& coeffs);

    // Función para obtener los coeficientes
    std::vector<double> getCoefficients() const;

    // Función para establecer las indeterminadas
    void setIndeterminates(const std::vector<std::string>& indets);

    // Función para obtener las indeterminadas
    std::vector<std::string> getIndeterminates() const;

    // Función para imprimir la información de la imagen
    void print() const;
};

#endif // PICTURE_H
