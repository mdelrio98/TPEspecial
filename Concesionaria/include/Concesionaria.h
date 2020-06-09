#ifndef CONCESIONARIA_H
#define CONCESIONARIA_H
#include "lista.h"
#include "auto.h"
using namespace std;

class Concesionaria
{
    public:
        Concesionaria();//CB
        virtual ~Concesionaria();
        void nuevo_auto(Auto a);//MOD
        bool existe_patente(string patente);//OBS
        void listar_modelo(int modelo, lista<Auto*>&listaPorModelo);//OBS
        // en la implementacion utilizamos un void pero en la especificacion de nereus devolvemos una lista
        void mayor_precio();//OBS
        void procesar_archivo_entrada(string origen);
        void  mostrar_lista();
        void  mostrar_lista_modelos(lista<Auto*>&listaPorModelo);
    private:
        lista<Auto>autos;
        Auto * mas_caro=NULL;
};

#endif // CONCESIONARIA_H
