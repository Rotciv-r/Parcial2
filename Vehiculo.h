#ifndef VEHICULO_H
#define VEHICULO_H

#include "Recurso.h"
#include <string>
using namespace std;

// Clase intermedia de la jerarquía. Sigue siendo abstracta porque NO
// implementa ejecutarAccion() (eso lo hacen Ambulancia y Helicoptero).
// Agrupa lo que tienen en común todos los vehículos: placa y capacidad.
class Vehiculo : public Recurso {
protected:
    string placa;
    int capacidad;

public:
    Vehiculo(string id, string nombre, string placa, int capacidad);

    void mostrarInfo() const override;

    virtual ~Vehiculo();
};

#endif
