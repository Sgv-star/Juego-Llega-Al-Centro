#ifndef JUEGO_H
#define JUEGO_H
#include <vector>
#include <Dado.h>
#include <Jugador.h>
#include <Tablero.h>
#include <iostream>
#include "fstream"

using namespace std;

class Juego
{
    public:
        Juego();
        Juego(vector<Jugador> jugadores, vector<Dado> dados, Tablero tablero);

        void setJugadores(vector<Jugador> jugadores);
        void setDados(vector<Dado> dados);
        void setTablero(Tablero tablero);
        void setDificultad(string dificultad);
        void setJuego();
        void setPartida(string p);

        bool moverJugadores(int numeroJugador);
        void jugar();


    protected:

    private:
        vector<Jugador> jugadores;
        vector<Dado> dados;
        Tablero tablero;
        int numeroJugadores;
        int indiceTurno;
        string dificultad;
        string partida;

};

#endif // JUEGO_H
