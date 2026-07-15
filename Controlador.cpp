#include "Controlador.h"
#include "Ambulancia.h"
#include "Helicoptero.h"
#include "Medico.h"
#include "Rescatista.h"
#include <iostream>
#include <limits>
using namespace std;

Controlador::Controlador() {
    cantidadRecursos = 0;
    capacidadRecursos = 5;
    listaRecursos = new Recurso*[capacidadRecursos];

    cantidadMisiones = 0;
    capacidadMisiones = 5;
    listaMisiones = new Mision*[capacidadMisiones];

    cargarDatosPrueba();
}

// ---------- Manejo de memoria dinamica (HT01) ----------

void Controlador::redimensionarRecursos() {
    int nuevaCapacidad = capacidadRecursos * 2;
    Recurso** nuevoArreglo = new Recurso*[nuevaCapacidad];

    for (int i = 0; i < cantidadRecursos; i++) {
        nuevoArreglo[i] = listaRecursos[i];
    }

    delete[] listaRecursos;
    listaRecursos = nuevoArreglo;
    capacidadRecursos = nuevaCapacidad;
}

void Controlador::redimensionarMisiones() {
    int nuevaCapacidad = capacidadMisiones * 2;
    Mision** nuevoArreglo = new Mision*[nuevaCapacidad];

    for (int i = 0; i < cantidadMisiones; i++) {
        nuevoArreglo[i] = listaMisiones[i];
    }

    delete[] listaMisiones;
    listaMisiones = nuevoArreglo;
    capacidadMisiones = nuevaCapacidad;
}

void Controlador::agregarRecursoInterno(Recurso* r) {
    if (cantidadRecursos == capacidadRecursos) {
        redimensionarRecursos();
    }
    listaRecursos[cantidadRecursos] = r;
    cantidadRecursos++;
}

void Controlador::agregarMisionInterna(Mision* m) {
    if (cantidadMisiones == capacidadMisiones) {
        redimensionarMisiones();
    }
    listaMisiones[cantidadMisiones] = m;
    cantidadMisiones++;
}

// ---------- Datos de prueba (HU05) ----------

void Controlador::cargarDatosPrueba() {
    // 2 ambulancias, 1 helicoptero, 2 medicos y 2 rescatistas
    agregarRecursoInterno(new Ambulancia("A01", "Ambulancia Norte", "VAL-101", 2));
    agregarRecursoInterno(new Ambulancia("A02", "Ambulancia Sur", "VAL-102", 2));
    agregarRecursoInterno(new Helicoptero("H01", "Halcon 1", "HEL-201", 4, 3.5));
    agregarRecursoInterno(new Medico("M01", "Dra. Ana Torres", "1002003", "Medicina de Urgencias"));
    agregarRecursoInterno(new Medico("M02", "Dr. Luis Rios", "1002004", "Trauma"));
    agregarRecursoInterno(new Rescatista("R01", "Carlos Mena", "1002005", "Rescate en Alturas"));
    agregarRecursoInterno(new Rescatista("R02", "Paula Diaz", "1002006", "Busqueda y Rescate"));

    // 2 misiones
    agregarMisionInterna(new Mision("MIS01", "Deslizamiento La Cumbre", "Ladera Occidental"));
    agregarMisionInterna(new Mision("MIS02", "Inundacion Rio Cauca", "Zona Ribera Norte"));
}

// ---------- Busquedas auxiliares ----------

Recurso* Controlador::buscarRecursoPorId(const string& id) {
    for (int i = 0; i < cantidadRecursos; i++) {
        if (listaRecursos[i]->getId() == id) {
            return listaRecursos[i];
        }
    }
    return nullptr;
}

Mision* Controlador::buscarMisionPorId(const string& id) {
    for (int i = 0; i < cantidadMisiones; i++) {
        if (listaMisiones[i]->getId() == id) {
            return listaMisiones[i];
        }
    }
    return nullptr;
}

// ---------- Opciones del menu ----------

void Controlador::verRecursos() {
    cout << "\n--- Recursos registrados (" << cantidadRecursos << ") ---" << endl;
    for (int i = 0; i < cantidadRecursos; i++) {
        listaRecursos[i]->mostrarInfo();
        cout << endl;
    }

    cout << "\n--- Misiones registradas (" << cantidadMisiones << ") ---" << endl;
    for (int i = 0; i < cantidadMisiones; i++) {
        listaMisiones[i]->mostrarInfo();
    }
}

void Controlador::registrarRecurso() {
    cout << "\nQue tipo de recurso desea registrar?" << endl;
    cout << "1. Ambulancia" << endl;
    cout << "2. Helicoptero" << endl;
    cout << "3. Medico" << endl;
    cout << "4. Rescatista" << endl;
    cout << "Opcion: ";

    int opcion;
    cin >> opcion;

    string id, nombre;
    cout << "ID unico del recurso: ";
    cin >> id;
    cout << "Nombre: ";
    cin.ignore();
    getline(cin, nombre);

    Recurso* nuevo = nullptr;

    if (opcion == 1 || opcion == 2) {
        string placa;
        int capacidad;
        cout << "Placa: ";
        cin >> placa;
        cout << "Capacidad (numero de personas): ";
        cin >> capacidad;

        if (opcion == 1) {
            nuevo = new Ambulancia(id, nombre, placa, capacidad);
        } else {
            double autonomia;
            cout << "Autonomia de vuelo (horas): ";
            cin >> autonomia;
            nuevo = new Helicoptero(id, nombre, placa, capacidad, autonomia);
        }
    } else if (opcion == 3 || opcion == 4) {
        string cedula, especialidad;
        cout << "Cedula: ";
        cin >> cedula;
        cout << "Especialidad: ";
        cin.ignore();
        getline(cin, especialidad);

        if (opcion == 3) {
            nuevo = new Medico(id, nombre, cedula, especialidad);
        } else {
            nuevo = new Rescatista(id, nombre, cedula, especialidad);
        }
    } else {
        cout << "Opcion invalida." << endl;
        return;
    }

    agregarRecursoInterno(nuevo);
    cout << "Recurso registrado con exito." << endl;
}

void Controlador::crearMision() {
    string id, nombre, zona;
    cout << "\nID unico de la mision: ";
    cin >> id;
    cout << "Nombre de la mision: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Zona afectada: ";
    getline(cin, zona);

    agregarMisionInterna(new Mision(id, nombre, zona));
    cout << "Mision creada con exito." << endl;
}

void Controlador::asignarRecursoAMision() {
    if (cantidadMisiones == 0) {
        cout << "No hay misiones creadas todavia." << endl;
        return;
    }

    string idMision, idRecurso;
    cout << "\nID de la mision: ";
    cin >> idMision;
    Mision* mision = buscarMisionPorId(idMision);
    if (mision == nullptr) {
        cout << "No se encontro la mision con ese ID." << endl;
        return;
    }

    cout << "ID del recurso a asignar: ";
    cin >> idRecurso;
    Recurso* recurso = buscarRecursoPorId(idRecurso);
    if (recurso == nullptr) {
        cout << "No se encontro el recurso con ese ID." << endl;
        return;
    }

    if (!recurso->getDisponible()) {
        cout << "Ese recurso ya esta asignado a otra mision." << endl;
        return;
    }

    // Se guarda el recurso en la mision como un Recurso* generico (HU02),
    // sin importar si por dentro es una Ambulancia, un Medico, etc.
    mision->agregarRecurso(recurso);
    cout << "Recurso asignado con exito a la mision." << endl;
}

void Controlador::ejecutarMisionMenu() {
    if (cantidadMisiones == 0) {
        cout << "No hay misiones creadas todavia." << endl;
        return;
    }

    string idMision;
    cout << "\nID de la mision a ejecutar: ";
    cin >> idMision;
    Mision* mision = buscarMisionPorId(idMision);
    if (mision == nullptr) {
        cout << "No se encontro la mision con ese ID." << endl;
        return;
    }

    mision->ejecutarMision();
}

// ---------- Menu principal (HU04) ----------

void Controlador::mostrarMenu() {
    cout << "\n============================================" << endl;
    cout << " Sistema de Gestion de Misiones de Rescate " << endl;
    cout << "============================================" << endl;
    cout << "1. Ver recursos" << endl;
    cout << "2. Registrar recurso" << endl;
    cout << "3. Crear mision" << endl;
    cout << "4. Asignar recurso a mision" << endl;
    cout << "5. Ejecutar mision" << endl;
    cout << "6. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

void Controlador::iniciar() {
    int opcion = -1;

    while (opcion != 6) {
        mostrarMenu();
        cin >> opcion;

        if (cin.fail()) {
            // el usuario escribio algo que no es un numero
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida, intente de nuevo." << endl;
            continue;
        }

        switch (opcion) {
            case 1:
                verRecursos();
                break;
            case 2:
                registrarRecurso();
                break;
            case 3:
                crearMision();
                break;
            case 4:
                asignarRecursoAMision();
                break;
            case 5:
                ejecutarMisionMenu();
                break;
            case 6:
                cout << "Cerrando el sistema. Liberando memoria..." << endl;
                break;
            default:
                cout << "Opcion invalida, intente de nuevo." << endl;
        }
    }
}

// ---------- Destructor: previene memory leaks (HT02) ----------

Controlador::~Controlador() {
    // 1. Liberar cada Mision (llama al destructor de Mision, que libera
    //    su arreglo interno de punteros, pero no los Recurso apuntados).
    for (int i = 0; i < cantidadMisiones; i++) {
        delete listaMisiones[i];
    }
    delete[] listaMisiones;

    // 2. Liberar cada Recurso real. Como el destructor de Recurso es
    //    virtual, aunque el puntero sea de tipo Recurso*, se llama al
    //    destructor correcto de la clase hija (Ambulancia, Medico, etc).
    for (int i = 0; i < cantidadRecursos; i++) {
        delete listaRecursos[i];
    }
    delete[] listaRecursos;
}
