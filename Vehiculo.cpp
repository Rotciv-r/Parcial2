#include "Vehiculo.h"
#include <iostream>
using namespace std;

Vehiculo::Vehiculo(string id, string nombre, string placa, int capacidad)
    : Recurso(id, nombre) { // llamamos al constructor del padre
    this->placa = placa;
    this->capacidad = capacidad;
}

void Vehiculo::mostrarInfo() const {
    Recurso::mostrarInfo(); // reusamos lo que ya imprime el padre
    cout << " | Placa: " << placa << " | Capacidad: " << capacidad;
}

Vehiculo::~Vehiculo() {
}
