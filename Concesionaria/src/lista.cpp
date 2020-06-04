#include "lista.h"
#include<string>
#include "Concesionaria.h"
#include "Auto.h"
#include <cstddef>
#include <cassert>
using namespace std;

template <typename T>
lista<T>::lista(){
    primero=NULL;
    //ctor
}
template <typename T>
lista<T>::~lista(){
    //vaciar();
}

template <typename T>
void lista<T>::vaciar(){
    Nodo * aux = primero;
    while(primero != NULL){
        aux = primero->sig;
        delete primero;
        primero = aux;
    }
    primero = NULL;
}

template <typename T>
void lista<T>::agregar_principio(const T & elemento){
    Nodo * nuevo = new Nodo();
    nuevo->elemento=elemento;
    nuevo->sig=primero;
    primero= nuevo;
}

template <typename T>
void lista<T>::agregar_elemento(int posicion,const T & nuevo_elemento){
    //la lista esta vacia
    if(posicion == 1)
        agregar_principio(nuevo_elemento);
    //la lista tiene elementos
    else{
        if(primero != NULL){
            if(cantidad_elementos()+1 >= posicion){
                int contador=2;//empieza en 2 porque me hace ir un nodo atrasado y puedo insertar bien
                Nodo * aux = primero;
                while((aux->sig!=NULL) && (contador<posicion)){
                    aux=aux->sig;
                    contador++;
                }
                Nodo*aux2=new Nodo();
                aux2->elemento=nuevo_elemento;
                aux2->sig=aux->sig;
                aux->sig=aux2;
            }
        }
    }
}

template <typename T>
void lista<T>::cursor_al_principio(){
     cursor_interno = this->primero;
}

template <typename T>
const T & lista<T>::recuperar_elemento()const{
    return cursor_interno->elemento;
}

template <typename T>
void lista<T>::avanzar_cursor(){
    cursor_interno = cursor_interno->sig;
}

template <typename T>
const T & lista<T>::recuperar_lista(int iteraciones)const{
    assert(iteraciones < cantidad_elementos());
    Nodo * cursor = this->primero;
    for(int i =0;i < iteraciones;i++)
        cursor = cursor->sig;

    return cursor->elemento;
}

template <typename T>
bool lista<T>::lista_vacia(){
    if (primero == NULL)
        return true;
    else
        return false;
}

template <typename T>
int lista<T>::cantidad_elementos()const{
    if(primero!=NULL){
        Nodo*aux = NULL;
        aux=primero;
        int contador=0;
        while(aux!=NULL){
            contador++;
            aux=aux->sig;
        }
        return contador;
    }
    else
        return 0;
}

template <typename T>
void lista<T>::eliminar_Primero(){
    Nodo * Aeliminar = primero;
    primero = primero->sig;
    delete Aeliminar;
}

template <typename T>
void lista<T>::eliminar_Arbitrario(T elemento){
    if (primero->sig != NULL){
        Nodo * cursor = primero;
        while ((cursor->sig != NULL) && (cursor->sig->elemento != elemento))
            cursor = cursor->sig;
        if ((cursor != NULL) and (cursor->sig != NULL)){
            Nodo * AEliminar = cursor->sig;
            cursor->sig=cursor->sig->sig;
            AEliminar->sig = NULL;
            delete AEliminar;
        }
    }
}
template <typename T>
void lista<T>::eliminar_elemento( T  elemento){
    if (primero != NULL){
        if (primero->elemento == elemento)
            eliminar_Primero();
        else
            eliminar_Arbitrario(elemento);
    }
}

template <typename T>
void lista<T>::eliminar_lista(){
    if (primero != NULL){
        Nodo * cursor = primero;
        while (primero != NULL){
            cursor = primero;
            primero = primero->sig;
            delete cursor;
        }
    }
}

template <typename T>
void lista<T>::mostrar_elementos(){
    Nodo * cursor = primero;
    while(cursor != NULL){
        cout << cursor->elemento << " " ;
        cursor = cursor->sig;
    }
}

template class lista<string>;
template class lista<Auto>;
