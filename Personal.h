#ifndef PERSONAL_H
#define PERSONAL_H

#include "Recurso.h"
#include <string>
using namespace std;

// Igual que Vehiculo: es la clase intermedia para todo el personal humano.
class Personal : public Recurso {
protected:
    string cedula;
    string especialidad;

public:
    Personal(string id, string nombre, string cedula, string especialidad);

    void mostrarInfo() const override;

    virtual ~Personal();
};

#endif
