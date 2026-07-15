#include "Recurso.h"
#include <iostream>
using namespace std;

Recurso::Recurso(string id, string nombre) {
    this->id = id;
    this->nombre = nombre;
    this->disponible = true; // al registrarse, un recurso arranca disponible
}

void Recurso::mostrarInfo() const {
    cout << "ID: " << id << " | Nombre: " << nombre
         << " | Disponible: " << (disponible ? "Si" : "No");
}

string Recurso::getId() const {
    return id;
}

string Recurso::getNombre() const {
    return nombre;
}

bool Recurso::getDisponible() const {
    return disponible;
}

void Recurso::setDisponible(bool valor) {
    disponible = valor;
}

Recurso::~Recurso() {
    // No hay memoria dinámica propia que liberar aquí, pero se deja el
    // destructor definido y virtual para que la cadena de destructores
    // de las clases hijas se ejecute correctamente.
}
