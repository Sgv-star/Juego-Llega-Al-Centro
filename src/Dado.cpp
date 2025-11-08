#include "Dado.h"

Dado::Dado()
{
    //ctor
}

Dado::Dado(int PVMaximo){
    this -> PVMaximo = PVMaximo;
}

int Dado::sacarNumero(){
    RNG rng = RNG(getPVMaximo());
    return rng.getRandom();
}

void Dado::setPVMaximo(int PVMaximo){
    this -> PVMaximo = PVMaximo;
}

int Dado::getPVMaximo(){
    return PVMaximo;
}
