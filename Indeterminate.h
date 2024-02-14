#ifndef INDETERMINATE_H
#define INDETERMINATE_H

#include "Dato.h"

class Indeterminate : public Dato {
public:
    Indeterminate(const std::string& namer);
    std::string getNombre() const override;
    void setValor(int value);
    int getValor() const override;
    void print() const override;

private:
    std::string name;
    int value;
};

#endif
