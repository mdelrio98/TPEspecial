#ifndef AUTO_H
#define AUTO_H
#include "Lista.h"
#include <string>
using namespace std;

class Auto
{
    public:
        Auto();
        Auto(int modelo,string patente, string marca, float precio,lista<string>caracteristicas);
        virtual ~Auto();
        int getmodelo(); //OBS
        string getmarca();// OBS
        string getpatente();// OBS
        float getprecio();// OBS
        lista<string> getCaracteristicas();//OBS
        bool operator < (const Auto & A) const;
        bool operator > (const Auto & A) const;
        bool operator == (const Auto & A) const;
        bool operator != (const Auto & A) const;
        void imprimirauto();

    private:
        int modelo;
        string patente;
        string marca;
        float precio;
        lista<string>caracteristicas;
};

#endif // AUTO_H
