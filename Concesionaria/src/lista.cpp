#include "lista.h"

template <typename T>
lista<T> lista<T>::lista(){
    primero=NULL;
    //ctor
}
template <typename T>
lista<T>lista::~lista(){
    //Tenemos que eliminar todos los punteros al heap con un while
    //dtor
}

template <typename T>
void lista<T>::agregar_elemento(const T & nuevo_elemento){
    Nodo * nuevo = crear_nodo(nuevo_elemento);
    //la lista esta vacia
    if(this->esvacia())
        this->;
    //la lista tiene elementos
    else{

    }
}

template <typename T>
lista<T>::nodo * lista<T>::crear_nodo(const T & elemento,Nodo * siguiente){
    Nodo * nuevo = new Nodo();
    nuevo->elemento=elemento;
    nuevo->siguiente=siguiente;
    return nuevo;
}


template class lista<string>;
template class lista<Concesionaria>;
template class lista<Auto>;
