#include "Jugador.h"

Jugador::Jugador()
{
    //ctor
}

Jugador::Jugador(string nombre, int PVInicial, int numeroJugador, pair<int, int> posicionActual){
    this -> nombre = nombre;
    this -> PVInicial = PVInicial;
    this -> PVActual = PVInicial;
    this -> numeroJugador = numeroJugador;
    this -> estado = true;
    this -> posicionActual = posicionActual;
}

void Jugador::setNombre(string nombre){
    this -> nombre = nombre;
}

void Jugador::setPVInicial(int PVInicial){
    this -> PVInicial = PVInicial;
}

void Jugador::setPVActual(int PVActual){
    this -> PVActual = PVActual;
}

void Jugador::setNumeroJugador(int numeroJugador){
    this -> numeroJugador = numeroJugador;
}

void Jugador::setEstado(bool estado){
    this -> estado = estado;
}

void Jugador::setPosicionActual(pair<int, int> posicionActual){
    this -> posicionActual = posicionActual;
}

string Jugador::getNombre(){
    return nombre;
}

int Jugador::getPVInicial(){
    return PVInicial;
}

int Jugador::getPVActual(){
    return PVActual;
}

int Jugador::getNumeroJugador(){
    return numeroJugador;
}

bool Jugador::getEstado(){
    return estado;
}

pair<int, int> Jugador::getPosicionActual(){
    return posicionActual;
}
