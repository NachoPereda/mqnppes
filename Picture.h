#ifndef PICTURE_H
#define PICTURE_H

#include <vector>
#include <utility>
#include <string>

class Picture {
private:
    std::vector<std::vector<std::pair<std::string, int>>> matrix;

public:
    void readFromFile(const std::string& filename);
    void printMatrix();
    void setValue(int rowIdx, int colIdx, int value);
};

#endif // PICTURE_H
