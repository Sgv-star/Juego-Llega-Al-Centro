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
}

void Juego::setJuego() {
    vector<vector<int>> tablero;

    if (dificultad == "facil") {

        int tamano = 15, centro = tamano / 2;
        tablero.resize(tamano, vector<int>(tamano, 0));

        for (int i = 0; i < tamano; i++) {
            for (int j = 0; j < tamano; j++) {

                if (i == centro && j == centro) {
                    cout << " X ";
                    continue;
                }

                bool hayJugador = false;

                for (int k = 0; k < jugadores.size(); k++) {
                    if (jugadores[k].getPosicionActual().first == i &&
                        jugadores[k].getPosicionActual().second == j) {

                        cout << " " << jugadores[k].getNumeroJugador() << " ";
                        hayJugador = true;
                        break;
                    }
                }

                if (!hayJugador)
                    cout << " . ";
            }
            cout << endl;
        }

    }
    else if (dificultad == "medio") {

        int tamano = 23, centro = tamano / 2;
        tablero.resize(tamano, vector<int>(tamano, 0));

        for (int i = 0; i < tamano; i++) {
            for (int j = 0; j < tamano; j++) {

                if (i == centro && j == centro) {
                    cout << " X ";
                    continue;
                }

                bool hayJugador = false;

                for (int k = 0; k < jugadores.size(); k++) {
                    if (jugadores[k].getPosicionActual().first == i &&
                        jugadores[k].getPosicionActual().second == j) {

                        cout << " " << jugadores[k].getNumeroJugador() << " ";
                        hayJugador = true;
                        break;
                    }
                }

                if (!hayJugador)
                    cout << " . ";
            }
            cout << endl;
        }

    }
    else if (dificultad == "dificil") {

        int tamano = 31, centro = tamano / 2;
        tablero.resize(tamano, vector<int>(tamano, 0));

        for (int i = 0; i < tamano; i++) {
            for (int j = 0; j < tamano; j++) {

                if (i == centro && j == centro) {
                    cout << " X ";
                    continue;
                }

                bool hayJugador = false;

                for (int k = 0; k < jugadores.size(); k++) {
                    if (jugadores[k].getPosicionActual().first == i &&
                        jugadores[k].getPosicionActual().second == j) {

                        cout << " " << jugadores[k].getNumeroJugador() << " ";
                        hayJugador = true;
                        break;
                    }
                }

                if (!hayJugador)
                    cout << " . ";
            }
            cout << endl;
        }
    }
}

//La idea aqui es que los dados se lancen segun la posicion del jugador y dentro del propio vector el orden es así (arriba, abajo, izquierda, derecha)
void Juego::moverJugadores(int numeroJugador){
    int x= jugadores[numeroJugador].getPosicionActual().first, y= jugadores[numeroJugador].getPosicionActual().second, eleccionSentido=0, tamano=tablero.getTamano();
    int arriba = -1, abajo = -1, izquierda = -1, derecha = -1;
    pair<int, int> posicionActual(x, y);

    if(x!=0 && x!=tablero.getTamano()-1 && y!=0 && y!=tablero.getTamano()-1){
        dados.resize(4);
        for(int i=0; i<dados.size(); i++){
            dados[i] = Dado(jugadores[numeroJugador].getPVInicial());
            switch(i){
            case 0:
                if(x>0){
                arriba = dados[i].sacarNumero();
                cout << "Arriba: " << arriba << endl;
                }
            case 1:
                if(x<tamano-1){
                abajo = dados[i].sacarNumero();
                cout << "Abajo: " << abajo << endl;
                }
            case 2:
                if(y>0){
                izquierda = dados[i].sacarNumero();
                cout << "Izquierda: " << izquierda << endl;
                }
            case 3:
                if(y<tamano-1){
                derecha = dados[i].sacarNumero();
                cout << "Derecha: " << derecha << endl;
                }
            }
        }
        vector<int> direcciones = {arriba, abajo, izquierda, derecha};
        do {
            cout << "Escoja un sentido (0: Arriba, 1: Abajo, 2: Izquierda, 3: Derecha): ";
            cin >> eleccionSentido;

            if (direcciones[eleccionSentido] == -1) {
                cout << " Movimiento inválido (fuera del tablero). Escoja una direccion valida." << endl;
            }

        } while (direcciones[eleccionSentido] == -1);
        jugadores[numeroJugador].setPVActual(jugadores[numeroJugador].getPVActual()-direcciones[eleccionSentido]);

        if(eleccionSentido==0 || eleccionSentido==1){
            if(eleccionSentido==0){
                posicionActual = {x-1, y};
            }
            else{
                posicionActual = {x+1, y};
            }
        }
        else{
            if(eleccionSentido==2){
                posicionActual = {x, y-1};
            }
            else{
                posicionActual = {x, y+1};
            }
        }
        jugadores[numeroJugador].setPosicionActual(posicionActual);

        setJuego();

        if (jugadores[numeroJugador].getPosicionActual().first == (tablero.getTamano()-1)/2 && jugadores[numeroJugador].getPosicionActual().second == (tablero.getTamano()-1)/2){
            cout << "Juego terminado"<<endl;
            cout << "El ganador es: " << jugadores[numeroJugador].getNombre() << endl;
        }
    }
}
