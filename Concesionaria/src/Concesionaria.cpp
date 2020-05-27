#include "Concesionaria.h"
#include <cstddef>
using namespace std;

Concesionaria::Concesionaria(){
    //ctor
}

Concesionaria::~Concesionaria(){
    //dtor
}
/*
bool Consecionaria::buscarPorPatente(string patente){
    int longLista = autos.longitud();

    for (int i = 0; i < longLista; i++){
        if (autos.devolverElementoEnPos(i).devolverPatente() == patente){
            return true;
        }
    }
}
*//*
bool Concesionaria::existePatente(string patente,arbol<Auto> &arbol_autos){
    if(!arbol_autos.arbolVacio()){
        int longlista= arbol_autos.cantidad_Elementos();

        for(int i=0; i < longlista ; i++){
            if(arbol_autos.getElemento(i) == patente){
                return true;
            }
            else
                return false;
        }
    }
}*/
