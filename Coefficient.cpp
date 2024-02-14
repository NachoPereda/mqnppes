#include "Coefficient.h"
#include <iostream>

Coefficient::Coefficient(const std::string& name) : name(name) {}

std::string Coefficient::getNombre() const {
    return name;
}

void Coefficient::setValor(int value){
    this->value=value;
}

int Coefficient::getValor() const {
    return value;
}

void Coefficient::print() const {
    std::cout << "Coefficient: Name = " << name << std::endl;
}
