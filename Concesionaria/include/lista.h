#ifndef LISTA_H
#define LISTA_H

template <typename T>
class lista
{
    public:
        lista();//constructor vacio
        lista();//constructor con parametros
        virtual ~lista();//destructor
        agregarnodo(const T & elemento);
        eliminarnodo();
    private:


};

#endif // LISTA_H
