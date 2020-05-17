#ifndef LISTA_H
#define LISTA_H

template <typename T>
class lista
{
    public:
        lista();//constructor vacio
        ~lista();//destructor
        void agregar_elemento(const T & nuevo_elemento, const & lista);
        int cantidad_elementos()const;
        bool eliminar_elemento();
        bool Listavacia();
        const T & recuperar_elemento();
    private:
        struct Nodo{
            T elemento;
            Nodo * siguente;
        };
        Nodo * primero;
};

#endif // LISTA_H
