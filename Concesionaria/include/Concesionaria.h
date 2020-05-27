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
        void  nuevoAuto(Auto a);
        bool existePatente(string patente);//OBS
        void listarModelo(int modelo, lista<Auto*>listaPorModelo);//OBS
        // en la implementacion utilizamos un void pero en la especificacion de nereus devolvemos una lista
        Auto mayorPrecio(arbol<Auto> &arbol_autos);//OBS
        void procesar_archivo_entrada(string origen);//, Contenedor & contenedor);
        void imprimirarbolautos();
    private:
        arbol<Auto>arbol_Autos;
};

#endif // CONCESIONARIA_H
