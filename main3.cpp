#include "Coefficient.h"
#include "Indeterminate.h"
#include "Picture.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <regex>

int main() {
    // Variable que contiene la expresión
    std::string rmqe = "p(1,1) * x1 * x1 + p(1,2) * x1 * x2 + p(1,3) * x1 * x3 + p(2,2) * x2 * x2 + p(2,3) * x2 * x3 + p(3,3) * x3 * x3 + p(1) * x1 + p(2) * x2 + p(3) * x3 + p(0)";

    // Crear un mapa para almacenar los coeficientes según nombres amigables
    std::map<std::string, Coefficient*> coefficientMap;
    // Crear un mapa para almacenar los indeterminados según nombres amigables
    std::map<std::string, Indeterminate*> indeterminateMap;

    // Expresión regular para buscar números entre paréntesis
    std::regex pattern("\\((\\d+),(\\d+)\\)");

    std::istringstream iss(rmqe);
    std::string term;
    while (iss >> term) {
        if (term.find("p") != std::string::npos) {
            // Es un coeficiente
            std::smatch match;
            if (std::regex_search(term, match, pattern) && match.size() == 3) {
                int i = std::stoi(match[1]);
                int j = std::stoi(match[2]);
                std::string friendlyName = "p" + std::to_string(i) + std::to_string(j);
                coefficientMap[friendlyName] = new Coefficient(term);
            }
        } else if (term.find("x") != std::string::npos) {
            // Es un indeterminado
            std::string friendlyName = term.substr(0, 2); // Tomar los dos primeros caracteres como nombre amigable
            indeterminateMap[friendlyName] = new Indeterminate(term); // Se inicializa con valor 0
        }
    }

    // Crear una Picture y establecer los elementos
    // Picture<Dato> picture(10, 10);
    // for (int i = 0; i < 3; ++i) {
    //     for (int j = i; j < 3; ++j) {
    //         std::string friendlyName = "p" + std::to_string(i + 1) + std::to_string(j + 1);
    //         if (coefficientMap.find(friendlyName) != coefficientMap.end()) {
    //             picture.setElement(i, j, coefficientMap[friendlyName]);
    //         }
    //     }
    // }
    // picture.print();

    // Imprimir los coeficientes
    std::cout << "Coeficientes:" << std::endl;
    for (const auto& pair : coefficientMap) {
        pair.second->print();
    }

    // Imprimir los indeterminados
    std::cout << "Indeterminados:" << std::endl;
    for (const auto& pair : indeterminateMap) {
        pair.second->print();
    }

    Picture<Dato> picture(4, 9);
    Coefficient p11 = coefficientMap["p11"];
    picture.setElement(0,0 ,p11);
    
    
    // if (coefficientMap.find("p11") != coefficientMap.end()) {
    //     // El coeficiente p(2,2) existe en el mapa
    //     Coefficient* p11 = coefficientMap["p11"];
    //     picture.setElement(0,0,p11);
    // }
    // if (coefficientMap.find("p22") != coefficientMap.end()) {
    //     // El coeficiente p(2,2) existe en el mapa
    //     Coefficient* p22 = coefficientMap["p22"];
    //     picture.setElement(0,2,p22);
    // }


    // Liberar la memoria de los coeficientes
    for (const auto& pair : coefficientMap) {
        delete pair.second;
    }

    // Liberar la memoria de los indeterminados
    for (const auto& pair : indeterminateMap) {
        delete pair.second;
    }

    return 0;
}
