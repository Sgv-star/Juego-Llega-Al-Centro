#include "Juego.h"

Juego::Juego()
{
    //ctor
}

Juego::Juego(vector<Jugador> jugadores, vector<Dado> dados, Tablero tablero){
    this -> jugadores = jugadores;
    this -> dados = dados;
    this -> tablero = tablero;
}

void Juego::setJugadores(vector<Jugador> jugadores){
    this -> jugadores = jugadores;
}

void Juego::setDados(vector<Dado> dados){
    this -> dados = dados;
}

void Juego::setTablero(Tablero tablero){
    this -> tablero = tablero;
}

void Juego::setDificultad(string dificultad){
    this -> dificultad = dificultad;

    if (dificultad=="facil"){
        Tablero tablero = Tablero(15);
        setTablero(tablero);

        vector<Dado> dados;
        for (int i=0; i<4; i++){
            dados[i] = Dado(15);
        }
        setDados(dados);
    }

    else if (dificultad=="medio"){
        Tablero tablero = Tablero(23);
        setTablero(tablero);

        vector<Dado> dados;
        for (int i=0; i<4; i++){
            dados[i] = Dado(23);
        }
        setDados(dados);
    }

    else if (dificultad=="dificil"){
        Tablero tablero = Tablero(31);
        setTablero(tablero);

        vector<Dado> dados;
        for (int i=0; i<4; i++){
            dados[i] = Dado(31);
        }
        setDados(dados);
    }
}
