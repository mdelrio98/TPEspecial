#ifndef LISTA_H
#define LISTA_H

template <typename T>
class lista
{
    public:
        lista();//constructor vacio
        ~lista();//destructor
        void agregar_elemento(const T & nuevo_elemento, const & lista);
        void agregar_principio(const T & elemento);
        int cantidad_elementos()const;
        bool existe_elemento()const;
        bool eliminar_elemento();
        bool eliminar_lista();
        bool listavacia();
        const T & recuperar_elemento();
    private:
        struct Nodo{
            T elemento;
            Nodo * siguente;
        };
        Nodo * primero;
        Nodo * cursor;
};

#endif // LISTA_H
