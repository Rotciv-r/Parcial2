#include "Ambulancia.h"
#include <iostream>
using namespace std;

Ambulancia::Ambulancia(string id, string nombre, string placa, int capacidad)
    : Vehiculo(id, nombre, placa, capacidad) {
}

void Ambulancia::ejecutarAccion() {
    cout << "[Ambulancia " << nombre << "] Transportando paciente via terrestre." << endl;
}
