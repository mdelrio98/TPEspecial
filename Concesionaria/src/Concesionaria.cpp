#include "Concesionaria.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstddef>
using namespace std;

Concesionaria::Concesionaria(){
    //ctor
}

Concesionaria::~Concesionaria(){
    //dtor
}

void  Concesionaria::imprimirarbolautos(){
    arbol_Autos.imprimirarbol();
}

void  Concesionaria::nuevoAuto(Auto a){
    arbol_Autos.agregar(a);
}

bool Concesionaria::existePatente(string patente){
    if(arbol_Autos.arbolVacio()!= true){
        Auto a1;
        a1.setpatente(patente);
        //cout<<"patente:"<<a1.getpatente()<<endl;
        if(arbol_Autos.existe_elemento(a1) == true){
           // cout<<"si";
            return true;
        }
    }
    return false;
}


//Comentarios: atoi y atof requieren un char * para converter a n�mero, usamos c_str de la clase string.
void Concesionaria::procesar_archivo_entrada(string origen)
{
    ifstream archivo(origen.c_str());
    if (!archivo.is_open())
        cout << "No se pudo abrir el archivo: " << origen << endl;
    else {
        string linea;
        getline(archivo, linea);
        int cantidad_autos = atoi(linea.c_str());
        cout << "Se cargar�n " << cantidad_autos << " autos." << endl;

        //Leemos de una linea completa por vez (getline).
        while (getline(archivo, linea)) {
            //Primer posici�n del separador ;
            int pos_inicial = 0;
            int pos_final = linea.find(';');

            //Informacion entre pos_inicial y pos_final
            int modelo = atoi(linea.substr(pos_inicial, pos_final).c_str());

            //Segunda posici�n del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            string marca = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Tercera posici�n del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            string patente = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Cuarta posici�n del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            float precio = atof(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());

            cout << modelo << "-"<<marca<<"-"<<patente<<"-"<<precio<<endl;
            //TO DO: Informacion general del auto.

            lista<string>carac;
            int contador=1;
            //Desde esta posici�n hasta el final se encuentra un n�mero variable de caracteristicas.
            string caracteristicas = linea.substr(pos_final + 1, linea.size());
            int pos_inicial_guion = 0, pos_final_guion = 0;
            while (pos_final_guion != -1) {
                pos_final_guion = caracteristicas.find('-', pos_inicial_guion);
                string caracteristica = caracteristicas.substr(pos_inicial_guion, pos_final_guion - pos_inicial_guion);
                pos_inicial_guion = pos_final_guion + 1;
                carac.agregar_elemento(contador,caracteristica);
                contador++;
                //TO DO: Nueva caracteristica encontrada.
            }
            Auto  a1(modelo,patente,marca,precio,carac);
            nuevoAuto(a1);
//            delete a1;
        }
    }
}


