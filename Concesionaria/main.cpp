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
    c.procesar_archivo_entrada("autos.csv");
    //existe patente
 //   c.imprimirarbolautos();
 //   cout<<"Hola"<<endl;
    string s= "QVP111";
    if(c.existePatente(s)== true){
        cout<<"Se encuentra la patente"<<endl;
    }
    else
        cout<<"No se encuentra la patente"<<endl;
    //Listar modelo
    lista<Auto*>listaPorModelo;
    c.listarModelo(2011,listaPorModelo);
//    c.imprimirlista(listaPorModelo);
    //Mayor precio
//    Auto a0;
//    a0 = c.mayorPrecio(arbol_Autos);
//    delete c;
    return 0;
}
