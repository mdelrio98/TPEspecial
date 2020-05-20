#include "arbol.h"
#include "auto.h"
#include "lista.h"
#include <cstddef>
using namespace std;

template <typename T>
arbol<T>::arbol(){
    this->auxArbol = NULL;
    //ctor
}

template <typename T>
arbol<T>::~arbol(){
    //dtor
}

template class arbol<Auto>;
