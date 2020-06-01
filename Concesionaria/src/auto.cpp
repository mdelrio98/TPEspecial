#include "auto.h"
#include <cstddef>
#include <iostream>
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

void Auto::imprimirauto(){
    cout<<this->patente<<endl;
}
void Auto::imprimirauto2(){
    cout<<this->modelo<<endl;
}

int Auto::getmodelo(){
    return this->modelo;
}

void Auto::setmodelo(int mod){
    this->modelo=mod;
}

string Auto::getmarca(){
    return this->marca;
}

string Auto::getpatente(){
    return this->patente;
}

void Auto::setpatente(string pat){
    this->patente=pat;
}

float Auto::getprecio(){
    return this->precio;
}

lista<string> Auto::getCaracteristicas(){
    return this->caracteristicas;
}

bool Auto::operator < (const Auto & A) const {
    if ((this->patente < A.patente) || (this->modelo < A.modelo)){
        return true; //si es menor
    }
    return false;
}

bool Auto::operator > (const Auto & A) const {
    if ((this->patente > A.patente) || (this->modelo > A.modelo)){
        return true; //si es mayor
    }
    return false;
}

bool Auto::operator == (const Auto & A) const {
    if ((this->patente == A.patente) || (this->modelo == A.modelo)){
        return true; //si son iguales
    }
    return false;
}
bool Auto::operator != (const Auto & A) const {
    if ((this->patente != A.patente) || (this->modelo != A.modelo)){
        return true; //si son iguales
    }
    return false;
}
