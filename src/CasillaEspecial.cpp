#include "CasillaEspecial.h"

CasillaEspecial::CasillaEspecial()
{
    //ctor
}

CasillaEspecial::CasillaEspecial(int PVMaximo)
{
    this -> descubierta = false;
    RNG rngValorCasillaEspecial = RNG(PVMaximo);
    this -> valor = rngValorCasillaEspecial.getRandom();
    RNG rngTipoCasillaEspecial = RNG(1);
    if (rngTipoCasillaEspecial.getRandom()==0){
        this -> tipo = "recompensa";
    }
    else{
        this -> tipo = "castigo";
    }
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
