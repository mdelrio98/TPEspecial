#ifndef CONCESIONARIA_H
#define CONCESIONARIA_H
#include "arbol.h"
#include "lista.h"
#include "auto.h"
using namespace std;

class Concesionaria
{
    public:
        Concesionaria();//CB
        virtual ~Concesionaria();
        bool existePatente();//OBS
        void listarModelo(int modelo, lista<Auto>listaPorModelo);//OBS
        // en la implementacion utilizamos un void pero en la especificacion de nereus devolvemos una lista
        Auto mayorPrecio();//OBS
    private:

};

#endif // CONCESIONARIA_H
