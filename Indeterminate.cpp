#include "Indeterminate.h"
#include <iostream>

Indeterminate::Indeterminate(const std::string& name) : name(name) {}

std::string Indeterminate::getNombre() const {
    return name;
}

void Indeterminate::setValor(int value){
    this->value=value;
}

int Indeterminate::getValor() const {
    return value;
}

void Indeterminate::print() const {
    std::cout << "Indeterminate: Nombre = " << name << std::endl;
}
