#include "Picture.h"
#include <iostream>
#include <fstream>
#include <sstream> // Para usar stringstream
#include <regex> // Para usar expresiones regulares

void Picture::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::pair<std::string, int>> row;
        std::stringstream ss(line); // Utilizamos stringstream para separar por comas
        std::string item;
        while (std::getline(ss, item, ',')) {
            // Eliminamos espacios en blanco al inicio y al final del item
            item = std::regex_replace(item, std::regex("^\\s+|\\s+$"), "");
            // Si el item está vacío, pasamos al siguiente
            if (item.empty()) {
                continue;
            }
            // Comprobamos si el item tiene el formato "nombre(valor)"
            std::regex pattern(R"(\s*(\w+)\((\d+),?(\d*)\)\s*)");
            std::smatch match;
            if (std::regex_match(item, match, pattern)) {
                std::string name = match[1];
                int value1 = std::stoi(match[2]);
                int value2 = match[3].str().empty() ? 0 : std::stoi(match[3]);
                row.push_back(std::make_pair(name, value1 * 10 + value2));
            } else {
                row.push_back(std::make_pair(item, 0));
            }
        }
        if (!row.empty()) { // Añadimos la fila solo si no está vacía
            matrix.push_back(row);
        }
    }

    file.close();
}

void Picture::printMatrix() {
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            std::cout << elem.first << "(" << elem.second << ") ";
        }
        std::cout << std::endl;
    }
}

void Picture::setValue(int rowIdx, int colIdx, int value) {
    if (rowIdx < 0 || rowIdx >= matrix.size() || colIdx < 0 || colIdx >= matrix[rowIdx].size()) {
        std::cerr << "Error: Index out of range." << std::endl;
        return;
    }
    matrix[rowIdx][colIdx].second = value;
}
