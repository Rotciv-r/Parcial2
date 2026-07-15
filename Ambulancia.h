#ifndef AMBULANCIA_H
#define AMBULANCIA_H

#include "Vehiculo.h"

// Clase concreta (hoja de la jerarquía). Aquí SI se implementa ejecutarAccion().
class Ambulancia : public Vehiculo {
public:
    Ambulancia(string id, string nombre, string placa, int capacidad);

    void ejecutarAccion() override;
};

#endif
