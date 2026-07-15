#include "Personal.h"
#include <iostream>
using namespace std;

Personal::Personal(string id, string nombre, string cedula, string especialidad)
    : Recurso(id, nombre) {
    this->cedula = cedula;
    this->especialidad = especialidad;
}

void Personal::mostrarInfo() const {
    Recurso::mostrarInfo();
    cout << " | Cedula: " << cedula << " | Especialidad: " << especialidad;
}

Personal::~Personal() {
}
