#include <iostream>
#include <string>
#include <Juego.h>
using namespace std;

int menu();
int menuNuevaPartida();

int main()
{
    vector<Juego> juegos;
    juegos[0] = Juego();
    int opcion = menu();

    do{
        switch(opcion){
        case 1:{
            int opcionNuevaPartida = menuNuevaPartida();
            switch(opcionNuevaPartida){
            case 1:{
                juegos[0].setDificultad("facil");

                int numeroJugadores=0;
                cout << "Ingrese el numero de jugadores: ";
                cin >> numeroJugadores;
                cout << endl;
                vector<Jugador> jugadores;
                for(int i=0; i<numeroJugadores; i++){
                    string nombre;
                    cout << "Ingrese el nombre del jugador " << i << ": ";
                    cin >> nombre;
                    if (i==0){
                        pair<int, int> posicionActual(0, 0);
                        jugadores[i] = Jugador(nombre, 15, i, posicionActual);
                    }
                    else if(i==1){
                        pair<int, int> posicionActual(0, 15);
                        jugadores[i] = Jugador(nombre, 15, i, posicionActual);
                    }
                    else if(i==2){
                        pair<int, int> posicionActual(15, 15);
                        jugadores[i] = Jugador(nombre, 15, i, posicionActual);
                    }
                    else if(i==3){
                        pair<int, int> posicionActual(15, 0);
                        jugadores[i] = Jugador(nombre, 15, i, posicionActual);
                    }
                }
                juegos[0].setJugadores(jugadores);

                break;
            }
            case 2:{
                juegos[0].setDificultad("medio");

                int numeroJugadores=0;
                cout << "Ingrese el numero de jugadores: ";
                cin >> numeroJugadores;
                cout << endl;
                vector<Jugador> jugadores;
                for(int i=0; i<numeroJugadores; i++){
                    string nombre;
                    cout << "Ingrese el nombre del jugador " << i << ": ";
                    cin >> nombre;
                    if (i==0){
                        pair<int, int> posicionActual(0, 0);
                        jugadores[i] = Jugador(nombre, 23, i, posicionActual);
                    }
                    else if(i==1){
                        pair<int, int> posicionActual(0, 23);
                        jugadores[i] = Jugador(nombre, 23, i, posicionActual);
                    }
                    else if(i==2){
                        pair<int, int> posicionActual(23, 23);
                        jugadores[i] = Jugador(nombre, 23, i, posicionActual);
                    }
                    else if(i==3){
                        pair<int, int> posicionActual(23, 0);
                        jugadores[i] = Jugador(nombre, 23, i, posicionActual);
                    }
                }
                juegos[0].setJugadores(jugadores);
                break;
            }
            case 3:{
                juegos[0].setDificultad("dificil");

                int numeroJugadores=0;
                cout << "Ingrese el numero de jugadores: ";
                cin >> numeroJugadores;
                cout << endl;
                vector<Jugador> jugadores;
                for(int i=0; i<numeroJugadores; i++){
                    string nombre;
                    cout << "Ingrese el nombre del jugador " << i << ": ";
                    cin >> nombre;
                    if (i==0){
                        pair<int, int> posicionActual(0, 0);
                        jugadores[i] = Jugador(nombre, 31, i, posicionActual);
                    }
                    else if(i==1){
                        pair<int, int> posicionActual(0, 31);
                        jugadores[i] = Jugador(nombre, 31, i, posicionActual);
                    }
                    else if(i==2){
                        pair<int, int> posicionActual(31, 31);
                        jugadores[i] = Jugador(nombre, 31, i, posicionActual);
                    }
                    else if(i==3){
                        pair<int, int> posicionActual(31, 0);
                        jugadores[i] = Jugador(nombre, 31, i, posicionActual);
                    }
                }
                juegos[0].setJugadores(jugadores);

                break;
            }
            }
        }
        case 2:{
            break;
        }
        case 3:{
            cout << "Gracias por jugar\n" << endl;
            break;
        }
        }
    } while(opcion != 3);

    return 0;
}

int menu(){
    int opcion;
    cout << "LLEGA AL CENTRO" << endl;
    cout << "1. Nueva partida" << endl;
    cout << "2. Cargar partida" << endl;
    cout << "3. Salir" << endl;
    cin >> opcion;
    cout << endl << endl;
    return opcion;
}

int menuNuevaPartida(){
    int opcion;
    cout << "Seleccione la dificultad:" << endl;
    cout << "1. Facil" << endl;
    cout << "2. Medio" << endl;
    cout << "3. Dificil" << endl;
    cin >> opcion;
    cout << endl << endl;
    return opcion;
}
