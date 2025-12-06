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

void Juego::setPartida(string partida){
    this -> partida = partida;
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
    int tamano = 0, banderaOpcionesSentidos=0;
    if (dificultad == "facil")      tamano = 15;
    else if (dificultad == "medio") tamano = 23;
    else if (dificultad == "dificil") tamano = 31;

    int x = jugadores[numeroJugador].getPosicionActual().first;
    int y = jugadores[numeroJugador].getPosicionActual().second;
    int eleccionSentido = 0;

    int arriba = -1, abajo = -1, izquierda = -1, derecha = -1;
    pair<int, int> posicionActual(x, y);


    int pvActual = jugadores[numeroJugador].getPVActual();

    dados.resize(4);
    for(int i = 0; i < (int)dados.size(); i++){
        dados[i] = Dado(jugadores[numeroJugador].getPVInicial());
        switch(i){
        case 0:
            if (x > 0) {
                int tirada = dados[i].sacarNumero();
                if (tirada <= pvActual) {
                    arriba = tirada;
                    cout << "Arriba: " << tirada << endl;
                    banderaOpcionesSentidos+=1;
                } else {
                    arriba = -1;
                    cout << "Arriba: X " << tirada
                     << " > PV actual " << pvActual << ")\n";
            }
        }
        break;
        case 1:
            if (x < tamano-1) {
                int tirada = dados[i].sacarNumero();
                if (tirada <= pvActual) {
                    abajo = tirada;
                    cout << "Abajo: " << tirada << endl;
                    banderaOpcionesSentidos+=1;
                } else {
                        abajo = -1;
                        cout << "Abajo: X " << tirada
                        << " > PV actual " << pvActual << ")\n";
                }
            }
        break;
        case 2:
            if (y > 0) {
            int tirada = dados[i].sacarNumero();
            if (tirada <= pvActual) {
                izquierda = tirada;
                cout << "Izquierda: " << tirada << endl;
                banderaOpcionesSentidos+=1;
            } else {
            izquierda = -1;
            cout << "Izquierda: X  " << tirada
                << " > PV actual " << pvActual << ")\n";
            }
        }
        break;
        case 3:
            if (y < tamano-1) {
            int tirada = dados[i].sacarNumero();
            if (tirada <= pvActual) {
                derecha = tirada;
                cout << "Derecha: " << derecha << endl;
                banderaOpcionesSentidos+=1;
            } else {
                derecha = -1;
                cout << "Derecha: X  " << tirada
                    << " > PV actual " << pvActual << ")\n";
                }
            }
            break;
        }
    }

    if (arriba == -1 && abajo == -1 && izquierda == -1 && derecha == -1) {
        cout << "No hay movimientos validos desde esta posicion. "
             << "Pierdes el turno.\n";
        // No cambiamos PV, no movemos al jugador
        return false; // el juego sigue, pero este jugador no se mueve
    }


    vector<int> direcciones = {arriba, abajo, izquierda, derecha};
    do {
        if(banderaOpcionesSentidos>1){
            cout << "Escoja un sentido (0: Arriba, 1: Abajo, 2: Izquierda, 3: Derecha): ";
            cin >> eleccionSentido;
        }
        else if(banderaOpcionesSentidos==1){
            for (int i=0; i<4; i++){
                if(direcciones[i] != -1){
                    eleccionSentido=i;
                    break;
                }
            }
        }

        if (eleccionSentido < 0 || eleccionSentido > 3) {
            cout << "Opcion fuera de rango. Intente de nuevo. "<<endl;
            continue;
        }

        if (direcciones[eleccionSentido] == -1) {
            cout << "Movimiento invalido. Escoja una direccion valida." << endl;
        }

    } while (eleccionSentido < 0 || eleccionSentido > 3 ||
             direcciones[eleccionSentido] == -1);


    jugadores[numeroJugador].setPVActual(
        jugadores[numeroJugador].getPVActual() - 1);

    if (jugadores[numeroJugador].getPVActual() <= 0) {
        cout << "El jugador " << jugadores[numeroJugador].getNombre()
             << " ha quedado eliminado (PV <= 0).\n";
        // No hace falta return true, el juego no termina aún;
        // solo marcamos que este jugador ya no puede jugar más.
    }


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
                    if(jugadores[numeroJugador].getPVInicial() < jugadores[numeroJugador].getPVActual()){
                        jugadores[numeroJugador].setPVInicial(jugadores[numeroJugador].getPVActual());
                    }
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
        cout<<"Jugador : "<<jugadores[j].getNombre() << "  Vida: "<<jugadores[j].getPVActual();
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

        //  1. Contar cuántos siguen vivos (PV > 0)
        int vivos = 0;
        int indiceUltimoVivo = -1;
        for (int i = 0; i < (int)jugadores.size(); i++) {
            if (jugadores[i].getPVActual() > 0) {
                vivos++;
                indiceUltimoVivo = i;
            }
        }

        //  2. Si solo queda uno vivo → gana automáticamente
        if (vivos == 1) {
            cout << "Juego terminado (solo queda un jugador con PV > 0).\n";
            cout << "El ganador es: " << jugadores[indiceUltimoVivo].getNombre()
                 << " con " << jugadores[indiceUltimoVivo].getPVActual() << " PV.\n";
            break;
        }

        //  3. Si ninguno tiene PV > 0 → desempate por quien tenga más PV
        if (vivos == 0) {
            int idxGanador = 0;
            int mejorPV = jugadores[0].getPVActual();
            for (int i = 1; i < (int)jugadores.size(); i++) {
                if (jugadores[i].getPVActual() > mejorPV) {
                    mejorPV = jugadores[i].getPVActual();
                    idxGanador = i;
                }
            }
            cout << "Todos los jugadores han llegado a PV <= 0.\n";
            cout << "Desempate por PV: gana "
                 << jugadores[idxGanador].getNombre()
                 << " con " << mejorPV << " PV.\n";
            break;
        }

        //  4. Saltar jugadores eliminados
        int intentos = 0;
        while (jugadores[turno].getPVActual() <= 0 && intentos < (int)jugadores.size()) {
            turno = (turno + 1) % jugadores.size();
            intentos++;
        }



        // (por seguridad, si todos estaban <= 0, ya lo manejamos arriba con vivos == 0)

        cout << "Turno del jugador "
             << jugadores[turno].getNumeroJugador()
             << " (" << jugadores[turno].getNombre() << ")\n";

        //  5. Juega el turno normalmente
        terminado = moverJugadores(turno);


        ofstream archivo(partida); // ACTUALIZA CONSTANTEMENTE LOS DATOS NECESARIOS PARA POSTERIORMENTE CARGAR LA PARTIDA
        if (archivo.is_open()) {
            archivo << dificultad << endl;
            archivo << tablero.getTamano() << endl;
            for (int i = 0; i<jugadores.size(); i++){
                archivo << jugadores[i].getNombre() << ";";
                archivo << jugadores[i].getPVInicial() << ";";
                archivo << jugadores[i].getNumeroJugador() << ";";
                archivo << jugadores[i].getPosicionActual().first << ";";
                archivo << jugadores[i].getPosicionActual().second << ";";
                archivo << jugadores[i].getPVActual() << ";";
                archivo << endl;
            }
        archivo.close();
        }

        // 6. Si no terminó por llegar al centro, pasar turno al siguiente
        if (!terminado) {
            turno = (turno + 1) % jugadores.size();

        }
    }
}

