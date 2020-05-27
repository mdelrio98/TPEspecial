#ifndef ARBOL_H
#define ARBOL_H
#include "lista.h"

template <typename T>
class arbol
{
    public:
        arbol();
        virtual ~arbol();
        void agregar_Nodo(const T & elemento);
        bool arbolVacio();
        void agregar(const T &  elemento);
        bool existe_elemento(const T &elemento);
        int cantidad_Elementos();
        //void listarElementos(lista<T> & listaElementos);
        T getElemento(int posicion);
    private:
        struct Nodo{
            T raiz;
            arbol*izq;
            arbol*der;
            };
        Nodo*Arbol;
};

#endif // ARBOL_H
