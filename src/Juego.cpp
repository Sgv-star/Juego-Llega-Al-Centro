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
bool Juego::moverJugadores(int numeroJugador){
    // 1. Determinar el tamaño del tablero según la dificultad
    int tamano = 0;
    if (dificultad == "facil")      tamano = 15;
    else if (dificultad == "medio") tamano = 23;
    else if (dificultad == "dificil") tamano = 31;

    // 2. Posición actual del jugador
    int x = jugadores[numeroJugador].getPosicionActual().first;
    int y = jugadores[numeroJugador].getPosicionActual().second;
    int eleccionSentido = 0;

    int arriba = -1, abajo = -1, izquierda = -1, derecha = -1;
    pair<int, int> posicionActual(x, y);

    // 3. Crear dados para cada dirección
    dados.resize(4);
    for(int i = 0; i < dados.size(); i++){
        dados[i] = Dado(jugadores[numeroJugador].getPVInicial());
        switch(i){
        case 0: // arriba
            if(x > 0){
                arriba = dados[i].sacarNumero();
                cout << "Arriba: " << arriba << endl;
            }
            break;
        case 1: // abajo
            if(x < tamano-1){
                abajo = dados[i].sacarNumero();
                cout << "Abajo: " << abajo << endl;
            }
            break;
        case 2: // izquierda
            if(y > 0){
                izquierda = dados[i].sacarNumero();
                cout << "Izquierda: " << izquierda << endl;
            }
            break;
        case 3: // derecha
            if(y < tamano-1){
                derecha = dados[i].sacarNumero();
                cout << "Derecha: " << derecha << endl;
            }
            break;
        }
    }

    // 4. Elegir dirección válida
    vector<int> direcciones = {arriba, abajo, izquierda, derecha};
    do {
        cout << "Escoja un sentido (0: Arriba, 1: Abajo, 2: Izquierda, 3: Derecha): ";
        cin >> eleccionSentido;

        if (eleccionSentido < 0 || eleccionSentido > 3) {
            cout << "Opción fuera de rango. Intente de nuevo.\n";
            continue;
        }

        if (direcciones[eleccionSentido] == -1) {
            cout << "Movimiento inválido (fuera del tablero). Escoja una direccion valida." << endl;
        }

    } while (eleccionSentido < 0 || eleccionSentido > 3 ||
             direcciones[eleccionSentido] == -1);

    // 5. Actualizar PV
    jugadores[numeroJugador].setPVActual(
        jugadores[numeroJugador].getPVActual() - direcciones[eleccionSentido]
    );

    // 6. Actualizar posición según dirección elegida
    if (eleccionSentido == 0) {          // arriba
        posicionActual = {x-1, y};
    } else if (eleccionSentido == 1) {   // abajo
        posicionActual = {x+1, y};
    } else if (eleccionSentido == 2) {   // izquierda
        posicionActual = {x, y-1};
    } else if (eleccionSentido == 3) {   // derecha
        posicionActual = {x, y+1};
    }

    jugadores[numeroJugador].setPosicionActual(posicionActual);

    // 7. Redibujar el tablero
    setJuego();

    // 8. Comprobar si llegó al centro
    int centro = (tamano - 1) / 2;
    if (jugadores[numeroJugador].getPosicionActual().first  == centro &&
        jugadores[numeroJugador].getPosicionActual().second == centro) {
        cout << "Juego terminado" << endl;
        cout << "El ganador es: " << jugadores[numeroJugador].getNombre() << endl;
        return true;
    }

    return false; // nadie ha ganado todavía
}



void Juego::jugar() {
    bool terminado = false;
    int turno = 0;


    while (!terminado) {
        cout << "Turno del jugador "<<endl
             << jugadores[turno].getNumeroJugador()
             << " (" << jugadores[turno].getNombre() << ")\n";

        // moverJugadores devuelve true si alguien ganó
        terminado = moverJugadores(turno);

        if (!terminado) {
            // pasar el turno al siguiente jugador
            turno = (turno + 1) % jugadores.size();
        }
    }
}

