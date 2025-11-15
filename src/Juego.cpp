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

void Juego::setDificultad(string dificultad) {
    this -> dificultad = dificultad;
    vector<vector<int>> tablero;

    if (dificultad == "facil") {
        int tamano = 15;
        int centro = tamano / 2;
        tablero.resize(tamano, vector<int>(tamano, 0));
        for (int i = 0; i < tamano; i++) {
            for (int j = 0; j < tamano; j++) {
                if (i == centro && j == centro) {

                    cout << " X ";

                } else {

                    cout << " . ";
                }
            }
        cout << endl;
        }


    } else if (dificultad == "medio") {
        int tamano = 23;
        int centro = tamano / 2;
        tablero.resize(tamano, vector<int>(tamano, 0));
        for (int i = 0; i < tamano; i++) {
            for (int j = 0; j < tamano; j++) {
                if (i == centro && j == centro) {

                    cout << " X ";

                } else {

                    cout << " . ";
                }
            }
        cout << endl;
        }


    } else if (dificultad == "dificil") {
        int tamano = 31;
        int centro = tamano / 2;
        tablero.resize(tamano, vector<int>(tamano, 0));
        for (int i = 0; i < tamano; i++) {
            for (int j = 0; j < tamano; j++) {
                if (i == centro && j == centro) {

                    cout << " X ";

                } else {

                    cout << " . ";
                }
            }
        cout << endl;
        }
    }
}
