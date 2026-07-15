#include "Rescatista.h"
#include <iostream>
using namespace std;

Rescatista::Rescatista(string id, string nombre, string cedula, string especialidad)
    : Personal(id, nombre, cedula, especialidad) {
}

void Rescatista::ejecutarAccion() {
    cout << "[Rescatista " << nombre << "] Buscando sobrevivientes en escombros." << endl;
}
