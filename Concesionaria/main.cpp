#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <cstddef>
#include "Concesionaria.h"
using namespace std;

/**
 * Abre el archivo según el origen, procesa las líneas del mismo y
 * almacena la información resultante en el contenedor pasado por referencia.
 **/


int main()
{

    Concesionaria c;
    c.procesar_archivo_entrada("prueba.csv");
    string s= "MLM111";
    if(c.existe_patente(s)== true){
        cout<<"Se encuentra la patente"<<endl;
    }
    else
        cout<<"No se encuentra la patente"<<endl;
    c.mostrar_lista();
    lista<Auto*>listaPorModelo;
    c.listar_modelo(2015,listaPorModelo);
    c.mayor_precio();
    return 0;
}
