#include "Controlador.h"

// Segun la HU04, main.cpp SOLO debe instanciar el Controlador
// y llamar a su metodo de inicio. Toda la logica vive dentro del
// Controlador y las clases a las que este delega.
int main() {
    Controlador controlador;
    controlador.iniciar();
    return 0;
}
