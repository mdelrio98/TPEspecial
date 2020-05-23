#include "auto.h"
#include <cstddef>
using namespace std;

Auto::Auto(){
    //ctor
}

Auto::Auto(int modelo,string patente, string marca, float precio,lista<string>caracteristicas){
    this->modelo=modelo;
    this->patente=patente;
    this->marca=marca;
    this->precio=precio;
    this->caracteristicas=caracteristicas;
    //ctor
}

Auto::~Auto(){
    //dtor
}

int Auto::getmodelo(){
    return this->modelo;
}

string Auto::getmarca(){
    return this->marca;
}

string Auto::getpatente(){
    return this->patente;
}

float Auto::getprecio(){
    return this->precio;
}

lista<string> Auto::getCaracteristicas(){
    return this->caracteristicas;
}
