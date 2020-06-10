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
    //delete mas_caro;
    //autos.eliminar_lista();
}


void  Concesionaria::mostrar_lista(){
    autos.mostrar_elementos();
}

void  Concesionaria::nuevo_auto(Auto a){
    bool inserto = false;
    autos.cursor_al_principio();
    int longlista = autos.get_cantelementos();
    if(longlista == 0){
            cout<<"longlista=0"<<endl;
        autos.agregar_elemento(1,a);
        mas_caro = new Auto(a);
    }
    if(longlista > 0){
        cout<<"longlista ="<<longlista<<" > 0"<<endl;
        int i = 1;
        while(( i <= longlista ) && (inserto == false)){
            Auto aux = autos.recuperar_lista(i);
            cout<<"while"<<endl;
            if(aux.getpatente() > a.getpatente()){//aux = OSD101 < a=YVC011
               autos.agregar_elemento(i,a);
                cout<<"cargo "<<a.getpatente()<<"en pos"<<i<<endl;
               if(a.getprecio() > mas_caro->getprecio())
                    mas_caro = new Auto(a);
               inserto = true;
            }
            else{
                autos.avanzar_cursor();
                i++;
            }
        }
    }
    autos.cursor_al_principio();
}

bool Concesionaria::existe_patente(string patente){
    bool found = false;
    autos.cursor_al_principio();
    int longlista = autos.get_cantelementos();
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

void Concesionaria::mayor_precio(){
    cout << "************************************" <<endl;
    cout << "El auto mas caro es: "<<endl;
    cout << "Auto:" <<endl;
    cout << "[(Patente:" << mas_caro->getpatente()<<")"<<endl;
    cout << "(Marca:" << mas_caro->getmarca()<<")"<<endl;
    cout << "(Modelo:" << mas_caro->getmodelo()<<")"<<endl;
    cout << "(Precio:" << mas_caro->getprecio()<<")"<<endl;
    cout << "(Caracteristicas:";
    for(int i=0; i < mas_caro->getcaracteristicas().get_cantelementos() ;i++){
        cout <<  mas_caro->getcaracteristicas().recuperar_lista(i) << ",";
    }
    cout << ")]" << endl ;
}


void Concesionaria::listar_modelo(int modelo, lista<Auto*>&listaPorModelo){
    if(autos.lista_vacia()!= true){
        int longlista= autos.get_cantelementos();
        autos.cursor_al_principio();
        int j=1;
        for(int i = 1; i <= longlista;i++){
            Auto  a= autos.recuperar_lista(i);
            Auto * nuevo = new Auto(a);
            if( a.getmodelo()== modelo){
                listaPorModelo.agregar_elemento(j,nuevo);
                cout<<"auto por modelo"<<a.getmarca()<<"//"<<a.getpatente()<<endl;
                j++;
            }
            autos.avanzar_cursor();
            delete nuevo;
        }
    }else
        cout<<"No hay autos";
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
        }
    }
}


