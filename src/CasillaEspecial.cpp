#include "CasillaEspecial.h"

CasillaEspecial::CasillaEspecial()
{
    this -> descubierta = false;
    //ctor
}

void CasillaEspecial::setTipo(string tipo){
    this -> tipo = tipo;
}

void CasillaEspecial::setDescubierta(bool descubierta){
    this -> descubierta = descubierta;
}

string CasillaEspecial::getTipo(){
    return tipo;
}

bool CasillaEspecial::getDescubierta(){
    return descubierta;
}
