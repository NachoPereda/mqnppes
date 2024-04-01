#ifndef PICTURE_H
#define PICTURE_H

#include <vector>
#include <utility>
#include <string>

class Picture {
private:
    std::vector<std::vector<std::pair<std::string, int>>> matrix;
    int n;

public:
    void readFromFile(const std::string& filename);
    void printMatrix();
    void setValue(int rowIdx, int colIdx, int value);
    std::string getId(int rowIdx, int colIdx);
    Picture clone() const;
    const std::vector<std::vector<std::pair<std::string, int>>>& getMatrix() const; // Método para acceder a la matriz
    int getN() const;
};

#endif // PICTURE_H
