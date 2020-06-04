#include "Concesionaria.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstddef>
#include <string>
using namespace std;

Concesionaria::Concesionaria(){
    //ctor
}

Concesionaria::~Concesionaria(){
    //dtor
}

void  Concesionaria::mostrar_lista(){
    autos.mostrar_elementos();
}

void  Concesionaria::nuevo_auto(Auto a){
    bool inserto = false;
    autos.cursor_al_principio();
    int longlista = autos.cantidad_elementos();
    cout<<"cargo:"<<a.getpatente()<<"/"<<longlista<<"/"<<endl;
    if(longlista == 0)
        autos.agregar_elemento(1,a);
    int i = 0;
    while(( i < longlista ) && (inserto == false)){
        Auto aux = autos.recuperar_lista(i);
        cout<<"pos"<<i<<endl;
        if((aux.getpatente().compare(a.getpatente())) > 0 ){
           cout<<"entre:"<<a.getpatente()<<endl;
           autos.agregar_elemento(i,a);
           inserto = true;
        }
        autos.avanzar_cursor();
        i++;
    }
}

bool Concesionaria::existe_patente(string patente){
    bool found = false;
    autos.cursor_al_principio();
    int longlista = autos.cantidad_elementos();
    int i = 0;
    while(( i < longlista ) && (found == false)){
        Auto a = autos.recuperar_lista(i);
        if(a.getpatente() == patente)
            found = true;
        autos.avanzar_cursor();
        i++;
    }
    return found;
}

/*
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
}*/

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

            Auto  a1(modelo,patente,marca,precio);
            int contador=1;

            //Desde esta posición hasta el final se encuentra un número variable de caracteristicas.
            string caracteristicas = linea.substr(pos_final + 1, linea.size());
            int pos_inicial_guion = 0, pos_final_guion = 0;
            while (pos_final_guion != -1) {
                pos_final_guion = caracteristicas.find('-', pos_inicial_guion);
                string caracteristica = caracteristicas.substr(pos_inicial_guion, pos_final_guion - pos_inicial_guion);
                pos_inicial_guion = pos_final_guion + 1;
                a1.setcaracteristica(contador,caracteristica);
                contador++;
                //TO DO: Nueva caracteristica encontrada.
            }
            nuevo_auto(a1);
           //delete a1;
        }
    }
}


