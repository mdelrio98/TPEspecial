#ifndef LISTA_H
#define LISTA_H

template <typename T>
class lista
{
    public:
        lista();//constructor
        ~lista();//destructor
        void vaciar();
        void agregar_elemento(int posicion,const T & nuevo_elemento);//MOD
        void agregar_principio(const T & elemento);//MOD
        int cantidad_elementos()const;//OBS
        bool existe_elemento()const;//OBS
        void eliminar_Primero();//MOD
        void eliminar_Arbitrario(T elemento);//MOD
        void eliminar_elemento( T  elemento);//MOD
        void eliminar_lista();//MOD
        bool lista_vacia();//OBS
        void cursor_al_principio();//MOD
        const T & recuperar_elemento()const;//OBS
        void avanzar_cursor();//MOD
        const T & recuperar_lista(int iteraciones)const;//OBS
        void mostrar_elementos();
    private:
        struct Nodo{
            T elemento;
            Nodo * sig;
        };
        Nodo * primero;
        Nodo * cursor_interno;
};

#endif // LISTA_H
