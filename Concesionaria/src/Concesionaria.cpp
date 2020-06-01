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
/*
void Concesionaria::imprimirlista(lista<Auto*>listaPorModelo){

    if(listaPorModelo!= NULL){
        cout<<"Tiene: "<<endl;
        int longlista= listaPorModelo.cantidad_elementos();
        for (int i=1;i < longlista;i++){
            cout<<"Patente"<< listaPorModelo.recuperar_elemento(i)->getpatente()<<endl;
            cout<<"Modelo"<< listaPorModelo.recuperar_elemento(i)->getmodelo()<<endl;
            cout<<"Marca"<< listaPorModelo.recuperar_elemento(i)->getmarca()<<endl;
            cout<<"Precio"<< listaPorModelo.recuperar_elemento(i)->getprecio()<<endl;
            lista<string> cara = listaPorModelo.recuperar_elemento(i)->getCaracteristicas();
            int j=0;
            while (cara != NULL){
                cout<<cara.recuperar_elemento(j)<<endl;
                cara= cara->sig;
                j++;
            }
        }
    }
}*/

void  Concesionaria::nuevoAuto(Auto a){
    arbol_Autos.agregar(a);
}

void Concesionaria::listarModelo(int modelo, lista<Auto*>&listaPorModelo){
    if(arbol_Autos.arbolVacio()!= true){
        int longlista= arbol_Autos.cantidad_Elementos();
        lista<Auto*>listaaux;
        for(int i = 1; i < longlista;i++){
            arbol_Autos.listarElementos(i,listaaux);
             Auto * a=listaaux.recuperar_elemento(i);
             //cout<<"crea";
            if( a->getmodelo()== modelo){
                listaPorModelo.agregar_elemento(i,a);
               // cout<<"auto:"<<a->getpatente()<<endl;
            }
        }
    }
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


//Comentarios: atoi y atof requieren un char * para converter a número, usamos c_str de la clase string.
void Concesionaria::procesar_archivo_entrada(string origen)
{
    ifstream archivo(origen.c_str());
    if (!archivo.is_open())
        cout << "No se pudo abrir el archivo: " << origen << endl;
    else {
        string linea;
        getline(archivo, linea);
        int cantidad_autos = atoi(linea.c_str());
        cout << "Se cargarán " << cantidad_autos << " autos." << endl;

        //Leemos de una linea completa por vez (getline).
        while (getline(archivo, linea)) {
            //Primer posición del separador ;
            int pos_inicial = 0;
            int pos_final = linea.find(';');

            //Informacion entre pos_inicial y pos_final
            int modelo = atoi(linea.substr(pos_inicial, pos_final).c_str());

            //Segunda posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            string marca = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Tercera posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            string patente = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Cuarta posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            float precio = atof(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());

            cout << modelo << "-"<<marca<<"-"<<patente<<"-"<<precio<<endl;
            //TO DO: Informacion general del auto.

            lista<string>carac;
            int contador=1;
            //Desde esta posición hasta el final se encuentra un número variable de caracteristicas.
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


