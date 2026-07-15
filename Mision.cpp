#include "Mision.h"
#include <iostream>
using namespace std;

Mision::Mision(string id, string nombre, string zonaAfectada, int capacidadInicial) {
    this->id = id;
    this->nombre = nombre;
    this->zonaAfectada = zonaAfectada;
    this->cantidadRecursos = 0;
    this->capacidadRecursos = capacidadInicial;

    // Reservamos el arreglo de punteros en el Heap (HT01)
    this->recursosAsignados = new Recurso*[capacidadRecursos];
}

void Mision::redimensionar() {
    int nuevaCapacidad = capacidadRecursos * 2;
    Recurso** nuevoArreglo = new Recurso*[nuevaCapacidad];

    for (int i = 0; i < cantidadRecursos; i++) {
        nuevoArreglo[i] = recursosAsignados[i];
    }

    delete[] recursosAsignados; // solo liberamos el arreglo viejo, no los objetos
    recursosAsignados = nuevoArreglo;
    capacidadRecursos = nuevaCapacidad;
}

void Mision::agregarRecurso(Recurso* recurso) {
    if (cantidadRecursos == capacidadRecursos) {
        redimensionar();
    }
    recursosAsignados[cantidadRecursos] = recurso;
    cantidadRecursos++;
    recurso->setDisponible(false); // el recurso queda ocupado en esta mision
}

void Mision::ejecutarMision() {
    cout << "\n=== Ejecutando mision: " << nombre << " (Zona: " << zonaAfectada << ") ===" << endl;

    if (cantidadRecursos == 0) {
        cout << "Esta mision no tiene recursos asignados todavia." << endl;
        return;
    }

    // Aqui esta el polimorfismo pedido en la HU03: no importa si el
    // puntero apunta a una Ambulancia, un Helicoptero, un Medico o un
    // Rescatista; cada uno responde a ejecutarAccion() con SU propio
    // comportamiento gracias a que el metodo es virtual.
    for (int i = 0; i < cantidadRecursos; i++) {
        recursosAsignados[i]->ejecutarAccion();
    }
}

void Mision::mostrarInfo() const {
    cout << "Mision [" << id << "] " << nombre
         << " | Zona: " << zonaAfectada
         << " | Recursos asignados: " << cantidadRecursos << endl;
}

string Mision::getId() const {
    return id;
}

string Mision::getNombre() const {
    return nombre;
}

int Mision::getCantidadRecursos() const {
    return cantidadRecursos;
}

Mision::~Mision() {
    // Solo liberamos el ARREGLO de punteros. Los objetos Recurso reales
    // los libera el Controlador, que es quien los creó con new.
    delete[] recursosAsignados;
}
