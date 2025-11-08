#include "Casilla.h"

Casilla::Casilla()
{
    //ctor
}

Casilla::Casilla(int fila, int columna){
    this -> fila = fila;
    this -> columna = columna;
    this -> esCasillaCentral = false;
}

void Casilla::setFila(int fila){
    this -> fila = fila;
}

void Casilla::setColumna(int columna){
    this -> columna = columna;
}

void Casilla::setEsCasillaCentral(bool esCasillaCentral){
    this -> esCasillaCentral = esCasillaCentral;
}

int Casilla::getFila(){
    return fila;
}

int Casilla::getColumna(){
    return columna;
}

bool getEsCasillaCentral(){
    return esCasillaCentral;
}
