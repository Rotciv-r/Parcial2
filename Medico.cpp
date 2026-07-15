#include "Medico.h"
#include <iostream>
using namespace std;

Medico::Medico(string id, string nombre, string cedula, string especialidad)
    : Personal(id, nombre, cedula, especialidad) {
}

void Medico::ejecutarAccion() {
    cout << "[Medico " << nombre << "] Estabilizando signos vitales." << endl;
}
