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
void lista<T>::agregar_principio(const T & elemento){
    Nodo * nuevo = new Nodo();
    nuevo->elemento=elemento;
    nuevo->siguiente=primero;
    primero= nuevo;
}

template <typename T>
void lista<T>::agregar_elemento(int posicion,const T & nuevo_elemento){
    //la lista esta vacia
    if(posicion == 1)
        agregar_principio(nuevo_elemento)
    //la lista tiene elementos
    else{
        if(primero != null){
            if(cantidad_elementos()+1 >= posicion){
                int contador=2;//empieza en 2 porque me hace ir un nodo atrasado y puedo insertar bien
                nodo * aux = primero;
                while((aux->sig!=NULL)and(contador<posicion)){
                    aux=aux->sig;
                    contador++;
                }
                nodo*aux2=new nodo;
                aux2->variable=variable;
                aux2->sig=aux->sig;
                aux->sig=aux2;
            }
        }
    }
}




template class lista<std::string>;
template class lista<Concesionaria>;
template class lista<Auto>;
