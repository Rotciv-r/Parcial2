#ifndef RECURSO_H
#define RECURSO_H

#include <string>
using namespace std;

// Clase base ABSTRACTA. Representa el concepto genérico "Recurso" que pide la HU02.
// Ni las ambulancias, ni los médicos, etc, se crean directamente a partir de esta
// clase, pero SI se guardan y se manipulan a través de punteros a este tipo (polimorfismo).
class Recurso {
protected:
    string id;
    string nombre;
    bool disponible;

public:
    Recurso(string id, string nombre);

    // Método virtual PURO -> obliga a cada clase hija a implementar su propio
    // comportamiento. Esto es lo que pide la HU03 (polimorfismo).
    virtual void ejecutarAccion() = 0;

    // Método virtual "normal": tiene un comportamiento por defecto, pero las
    // clases hijas pueden extenderlo (lo hacen con "Recurso::mostrarInfo()" + su parte).
    virtual void mostrarInfo() const;

    string getId() const;
    string getNombre() const;
    bool getDisponible() const;
    void setDisponible(bool valor);

    // Destructor virtual: OBLIGATORIO en clases base cuando se va a hacer
    // "delete" sobre un puntero de tipo Recurso* que en realidad apunta a un
    // objeto hijo (Ambulancia, Medico, etc). Si no fuera virtual, se llamaría
    // solo al destructor de Recurso y se generaría una fuga de memoria (HT02).
    virtual ~Recurso();
};

#endif
