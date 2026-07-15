#ifndef MISION_H
#define MISION_H

#include "Recurso.h"
#include <string>
using namespace std;

// La Mision NO es dueña de los recursos (no los crea ni los destruye).
// Los recursos viven en el inventario general del Controlador; la Mision
// solo guarda PUNTEROS a ellos (relación de asociación/agregación, no
// composición). Por eso su destructor solo libera el arreglo de punteros,
// nunca los objetos Recurso apuntados.
class Mision {
private:
    string id;
    string nombre;
    string zonaAfectada;

    Recurso** recursosAsignados; // arreglo dinámico de punteros (HT01)
    int cantidadRecursos;
    int capacidadRecursos;

    void redimensionar(); // duplica la capacidad cuando el arreglo se llena

public:
    Mision(string id, string nombre, string zonaAfectada, int capacidadInicial = 5);

    // Recibe el recurso por puntero (HT03: nunca por copia/valor).
    void agregarRecurso(Recurso* recurso);

    // Recorre los recursos y llama a su ejecutarAccion() -> polimorfismo (HU03)
    void ejecutarMision();

    void mostrarInfo() const;

    string getId() const;
    string getNombre() const;
    int getCantidadRecursos() const;

    ~Mision();
};

#endif
