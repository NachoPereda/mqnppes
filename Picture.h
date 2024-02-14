#ifndef PICTURE_H
#define PICTURE_H

#include "Dato.h"
#include <vector>

template<typename T>
class Picture {
private:
    std::vector<std::vector<T>> data;

public:
    Picture(int rows, int cols);
    void setElement(int row, int col, T value);
    T* getElement(int row, int col) const;
    int numRows() const;
    int numCols() const;
    void print() const;
    ~Picture();
};

#endif
