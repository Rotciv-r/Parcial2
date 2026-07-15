#ifndef HELICOPTERO_H
#define HELICOPTERO_H

#include "Vehiculo.h"

class Helicoptero : public Vehiculo {
private:
    double autonomiaVueloHoras; // atributo propio de esta clase hoja

public:
    Helicoptero(string id, string nombre, string placa, int capacidad, double autonomiaVueloHoras);

    void ejecutarAccion() override;
};

#endif
