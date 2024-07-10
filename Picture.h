#ifndef PICTURE_H
#define PICTURE_H

#include <vector>
#include <utility>
#include <string>

class Picture
{
private:
    std::vector<std::vector<std::pair<std::string, int>>> matrix;
    int n;
    std::vector<std::pair<int, int>> p_elements;

public:
    void readFromFile(const std::string &filename);
    void assignCoefficients(const std::string &filename);
    void printMatrix();
    void setValue(int rowIdx, int colIdx, int value);
    std::string getId(int rowIdx, int colIdx);
    Picture clone() const;
    std::vector<std::vector<std::pair<std::string, int>>> &getMatrix(); // Método para acceder a la matriz
    std::pair<std::string, int> getMatrixElement( int i, int j);
    int getN() const;
    int getRows();
    int getColumns();
    std::vector<std::pair<int, int>> getPindex();
};

#endif // PICTURE_H
