#include "Picture.h"
#include <iomanip>
#include <iostream>

template<typename T>
Picture<T>::Picture(int rows, int cols) : data(rows, std::vector<T>(cols, nullptr)) {}

template<typename T>
void Picture<T>::setElement(int row, int col, T value) {
    if (data[row][col] != nullptr)
        delete data[row][col];
    data[row][col] = value;
}

template<typename T>
T* Picture<T>::getElement(int row, int col) const {
    return data[row][col];
}

template<typename T>
int Picture<T>::numRows() const {
    return data.size();
}

template<typename T>
int Picture<T>::numCols() const {
    return data[0].size();
}

template<typename T>
void Picture<T>::print() const {
    for (const auto& row : data) {
        for (const auto& element : row) {
            if (element != nullptr)
                element->print();
            else
                std::cout << std::setw(10) << "NULL";
        }
        std::cout << std::endl;
    }
}

template<typename T>
Picture<T>::~Picture() {
    // Liberar la memoria de los objetos almacenados
    for (auto& row : data) {
        for (auto& element : row) {
            if (element != nullptr)
                delete element;
        }
    }
}

template class Picture<Dato>;
