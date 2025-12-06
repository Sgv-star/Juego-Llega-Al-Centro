#include "RNG.h"

RNG::RNG()
{
    //ctor
}

RNG::RNG(int valorMaximo){
    this -> rng = mt19937(random_device{}());
    this -> dist = uniform_int_distribution<int>(1, valorMaximo);
}

void RNG::setValorMaximo(int valorMaximo){
    this -> dist = uniform_int_distribution<int>(1, valorMaximo);
}

int RNG::getValorMaximo(){
    return valorMaximo;
}

int RNG::getRandom(){
    return dist(rng);
}
