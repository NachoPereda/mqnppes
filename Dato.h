#ifndef DATO_H
#define DATO_H

#include <string>

class Dato {
public:
    virtual ~Dato() {} // Necesario para la correcta destrucción de los objetos derivados
    virtual std::string getNombre() const = 0; // Método virtual puro para obtener el nombre
    virtual int getValor() const = 0; // Método virtual puro para obtener el valor
    virtual void print() const = 0; // Método virtual puro para imprimir el objeto
};

#endif
