#ifndef LISTA_H
#define LISTA_H

template <typename T>
class lista
{
    public:
        lista();//constructor vacio
        ~lista();//destructor
<<<<<<< Updated upstream
        void agregar_elemento(const T & nuevo_elemento, const & lista);
        int cantidad_elementos()const;
        bool eliminar_elemento();
        bool Listavacia();
        const T & recuperar_elemento();
=======
        void agregar_elemento(int posicion,const T & nuevo_elemento);//MOD
        void agregar_principio(const T & elemento);//MOD
        int cantidad_elementos();//OBS
        bool existe_elemento()const;//OBS
        void eliminar_elemento();       //no se que parametro va      //MOD
        void eliminar_lista();//MOD
        bool listavacia();//OBS
        const T & recuperar_elemento();//OBS
>>>>>>> Stashed changes
    private:
        struct Nodo{
            T elemento;
            Nodo * siguente;
        };
        Nodo * primero;
};

#endif // LISTA_H
