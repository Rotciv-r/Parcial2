#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "Recurso.h"
#include "Mision.h"
#include <string>
using namespace std;

// El Controlador es la UNICA clase que main.cpp instancia (HU04).
// Es dueño real de los Recursos y de las Misiones: los crea con new
// y por lo tanto es el responsable de destruirlos con delete (HT02).
class Controlador {
private:
    Recurso** listaRecursos;
    int cantidadRecursos;
    int capacidadRecursos;

    Mision** listaMisiones;
    int cantidadMisiones;
    int capacidadMisiones;

    void redimensionarRecursos();
    void redimensionarMisiones();

    void agregarRecursoInterno(Recurso* r); // uso interno, evita repetir codigo
    void agregarMisionInterna(Mision* m);

    // Metodo "oculto": el usuario nunca lo ve en el menu, solo se ejecuta
    // una vez al arrancar el programa (HU05).
    void cargarDatosPrueba();

    void mostrarMenu();
    void verRecursos();
    void registrarRecurso();
    void crearMision();
    void asignarRecursoAMision();
    void ejecutarMisionMenu();

    Recurso* buscarRecursoPorId(const string& id);
    Mision* buscarMisionPorId(const string& id);

public:
    Controlador();

    // Metodo de inicio: main.cpp solo llama a esto (HU04).
    void iniciar();

    ~Controlador();
};

#endif
