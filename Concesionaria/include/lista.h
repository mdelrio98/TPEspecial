#ifndef LISTA_H
#define LISTA_H

template <typename T>
class lista
{
    public:
        lista();//constructor
        ~lista();//destructor
        void agregar_elemento(int posicion,const T & nuevo_elemento);//MOD
        void agregar_principio(const T & elemento);//MOD
        int cantidad_elementos();//OBS
        bool existe_elemento()const;//OBS
        void eliminar_Primero();//MOD
        void eliminar_Arbitrario(T elemento);//MOD
        void eliminar_elemento( T  elemento);//MOD
        void eliminar_lista();//MOD
        bool listavacia();//OBS
        const T recuperar_elemento(int iteraciones);//OBS
    private:
        struct Nodo{
            T elemento;
            Nodo * sig;
        };
        Nodo * primero;
};

#endif // LISTA_H
