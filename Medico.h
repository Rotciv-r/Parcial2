#ifndef MEDICO_H
#define MEDICO_H

#include "Personal.h"

class Medico : public Personal {
public:
    Medico(string id, string nombre, string cedula, string especialidad);

    void ejecutarAccion() override;
};

#endif
