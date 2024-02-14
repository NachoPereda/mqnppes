#ifndef COEFFICIENT_H
#define COEFFICIENT_H

#include "Dato.h"

class Coefficient : public Dato {
public:
    Coefficient(const std::string& name);
    std::string getNombre() const override;
    void setValor(int value);
    int getValor() const override;
    void print() const override;

private:
    std::string name;
    int value;
};

#endif
