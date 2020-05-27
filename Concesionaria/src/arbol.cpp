#include "arbol.h"
#include "auto.h"
#include "lista.h"
#include <iostream>
#include <cstddef>
using namespace std;

template <typename T>
arbol<T>::arbol(){
    Arbol = NULL;
    //ctor
}

template <typename T>
arbol<T>::~arbol(){
    //dtor
}

template <typename T>
void arbol<T>::imprimirarbol(){
    if(Arbol!=NULL){
        Arbol->izq->imprimirarbol();
        Arbol->raiz.imprimirauto();
        Arbol->der->imprimirarbol();
    }
}

template <typename T>
bool arbol<T>::arbolVacio(){
    if(Arbol == NULL){
        return true;
    }
    else
        return false;
}

template <typename T>
void arbol<T>::agregar_Nodo(const T & elemento){
    Arbol=new Nodo();
    Arbol->raiz=elemento;
    Arbol->izq = new arbol();
    Arbol->der = new arbol();
}



template<typename T>
void arbol<T>::agregar(const T &elemento){
        if(Arbol == NULL){
            agregar_Nodo(elemento);
        }
        else{
            if (elemento > Arbol->raiz){
                Arbol->der->agregar(elemento);
            }
            else{
                if (elemento < Arbol->raiz){
                    Arbol->izq->agregar(elemento);
                }
            }
        }
}

template<typename T>
bool arbol<T>::existe_elemento(const T &elemento){
    if(Arbol == NULL){
        return false;
    }else
        if( Arbol->raiz == elemento)
            return true;
        else{
            if( Arbol->raiz > elemento){
                return Arbol->izq->existe_elemento(elemento);
            }else
                return Arbol->der->existe_elemento(elemento);
        }
}

template<typename T>
int arbol<T>::cantidad_Elementos(){
    if (Arbol!=NULL){
            return 1+ Arbol->der->cantidad_Elementos() + Arbol->izq->cantidad_Elementos();
       }else
            return 0;
}


template<typename T>
T * arbol<T>::getElemento(const T &elemento){
    if(Arbol == NULL)
        return NULL;
    else
    {
        if( Arbol->raiz == elemento)
            return &(Arbol->raiz);
        else{
            if( Arbol->raiz > elemento){
                return Arbol->izq->getElemento(elemento);
            }else
                return Arbol->der->getElemento(elemento);
        }
    }
}


template class arbol<Auto>;
