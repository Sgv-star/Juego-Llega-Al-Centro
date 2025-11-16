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
    int tamano = tablero.getTamano();
    int centro = tamano / 2;

    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano; j++) {

            bool hayJugador = false;


            for (int k = 0; k < jugadores.size(); k++) {
                if (jugadores[k].getPosicionActual().first == i &&
                    jugadores[k].getPosicionActual().second == j) {

                    cout << " " << jugadores[k].getNumeroJugador() << " ";
                    hayJugador = true;
                    break;
                }
            }

            if (hayJugador) continue;


            if (i == centro && j == centro) {
                cout << " X ";
                continue;
            }


            if (tablero.getEsEspecial(i, j)) {
                if (tablero.getDescubierta(i, j)) {
                    int valor = tablero.getValor(i, j);

                    if (valor > 0) {
                        cout << " R ";
                    } else if (valor < 0) {
                        cout << " C ";
                    } else {
                        cout << " e ";
                    }
                } else {

                    cout << " E ";
                }
            } else {

                cout << " . ";
            }
        }
        cout << endl;
    }
}


//La idea aqui es que los dados se lancen segun la posicion del jugador y dentro del propio vector el orden es así (arriba, abajo, izquierda, derecha)
bool Juego::moverJugadores(int numeroJugador){
    int tamano = 0;
    if (dificultad == "facil")      tamano = 15;
    else if (dificultad == "medio") tamano = 23;
    else if (dificultad == "dificil") tamano = 31;

    int x = jugadores[numeroJugador].getPosicionActual().first;
    int y = jugadores[numeroJugador].getPosicionActual().second;
    int eleccionSentido = 0;

    int arriba = -1, abajo = -1, izquierda = -1, derecha = -1;
    pair<int, int> posicionActual(x, y);

    dados.resize(4);
    for(int i = 0; i < dados.size(); i++){
        dados[i] = Dado(jugadores[numeroJugador].getPVInicial());
        switch(i){
        case 0:
            if(x > 0){
                arriba = dados[i].sacarNumero();
                cout << "Arriba: " << arriba << endl;
            }
            break;
        case 1:
            if(x < tamano-1){
                abajo = dados[i].sacarNumero();
                cout << "Abajo: " << abajo << endl;
            }
            break;
        case 2:
            if(y > 0){
                izquierda = dados[i].sacarNumero();
                cout << "Izquierda: " << izquierda << endl;
            }
            break;
        case 3:
            if(y < tamano-1){
                derecha = dados[i].sacarNumero();
                cout << "Derecha: " << derecha << endl;
            }
            break;
        }
    }


    vector<int> direcciones = {arriba, abajo, izquierda, derecha};
    do {
        cout << "Escoja un sentido (0: Arriba, 1: Abajo, 2: Izquierda, 3: Derecha): ";
        cin >> eleccionSentido;

        if (eleccionSentido < 0 || eleccionSentido > 3) {
            cout << "Opcion fuera de rango. Intente de nuevo. "<<endl;
            continue;
        }

        if (direcciones[eleccionSentido] == -1) {
            cout << "Movimiento invalido (fuera del tablero). Escoja una direccion valida." << endl;
        }

    } while (eleccionSentido < 0 || eleccionSentido > 3 ||
             direcciones[eleccionSentido] == -1);


    jugadores[numeroJugador].setPVActual(
        jugadores[numeroJugador].getPVActual() - 1
    );


    if (eleccionSentido == 0) {
        posicionActual = {x-1, y};
    } else if (eleccionSentido == 1) {
        posicionActual = {x+1, y};
    } else if (eleccionSentido == 2) {
        posicionActual = {x, y-1};
    } else if (eleccionSentido == 3) {
        posicionActual = {x, y+1};
    }

    jugadores[numeroJugador].setPosicionActual(posicionActual);

    int np = posicionActual.first;
    int yp = posicionActual.second;
    int eleccion;
        if(tablero.getEsEspecial(np,yp)){
        if(!tablero.getDescubierta(np,yp)){
            tablero.descubrir(np,yp);
            int valor = tablero.getValor(np,yp);
            if (valor > 0){
                cout<<"Casilla de recompensa: "<<valor<<endl;
                cout<<"1. Para quitar vida a oponente"<<endl;
                cout<<"2. Para dar vida al ocupante "<<endl;
                cin>>eleccion;
                while (eleccion > 2 || eleccion < 1){
                    cout<<"Eleccion fuera de rango"<<endl;
                    cin>>eleccion;
                }

                if(eleccion == 2){
                    jugadores[numeroJugador].setPVActual(jugadores[numeroJugador].getPVActual() + valor);
                }else if (eleccion == 1){

                int num = jugadores[numeroJugador].getNumeroJugador();
                for (int i = 0; i< (int)jugadores.size(); i++){

                    if(num != jugadores[i].getNumeroJugador()){
                        jugadores[i].setPVActual(jugadores[i].getPVActual() - valor);
                    }
                }
                cout<<"Vida restada a oponente: "<<valor<<endl;
                }



            }else if(valor < 0){
            cout<<"Mala suerte, Pierdes: "<<valor<<endl;
            jugadores[numeroJugador].setPVActual(jugadores[numeroJugador].getPVActual() + valor);
            }

        }else{
        cout<<"Ya conocemos esta casilla"<<endl;
        }
}
    cout<<"Puntos de vida actual"<<endl;
    for(int j = 0; j < (int)jugadores.size(); j ++){
        cout<<"Jugador : "<<jugadores[j].getNombre() << "Vida: "<<jugadores[j].getPVActual();
        cout<<endl;
    }
    setJuego();


    int centro = (tamano - 1) / 2;
    if (jugadores[numeroJugador].getPosicionActual().first  == centro &&
        jugadores[numeroJugador].getPosicionActual().second == centro) {
        cout << "Juego terminado" << endl;
        cout << "El ganador es: " << jugadores[numeroJugador].getNombre() << endl;
        return true;
    }
    return false;
}



void Juego::jugar() {
    bool terminado = false;
    int turno = 0;


    while (!terminado) {
        cout << "Turno del jugador "<<endl
             << jugadores[turno].getNumeroJugador()
             << " (" << jugadores[turno].getNombre() << ")\n";


        terminado = moverJugadores(turno);

        if (!terminado) {

            turno = (turno + 1) % jugadores.size();
        }
    }
}

