#ifndef JUEGO_H
#define JUEGO_H
#include <vector>
#include <Dado.h>
#include <Jugador.h>
#include <Tablero.h>
using namespace std;
#include <iostream>
class Juego
{
    public:
        Juego();
        Juego(vector<Jugador> jugadores, vector<Dado> dados, Tablero tablero);

        void setJugadores(vector<Jugador> jugadores);
        void setDados(vector<Dado> dados);
        void setTablero(Tablero tablero);
        void setDificultad(string dificultad);


    protected:

    private:
        vector<Jugador> jugadores;
        vector<Dado> dados;
        Tablero tablero;
        int numeroJugadores;
        int indiceTurno;
        string dificultad;

};

#endif // JUEGO_H
