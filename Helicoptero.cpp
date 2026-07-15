#include "Helicoptero.h"
#include <iostream>
using namespace std;

Helicoptero::Helicoptero(string id, string nombre, string placa, int capacidad, double autonomiaVueloHoras)
    : Vehiculo(id, nombre, placa, capacidad) {
    this->autonomiaVueloHoras = autonomiaVueloHoras;
}

void Helicoptero::ejecutarAccion() {
    cout << "[Helicoptero " << nombre << "] Realizando extraccion aerea." << endl;
}
