#include <iostream>
#include <string>
#include <Juego.h>
#include <string>
#include "fstream"
#include "sstream"
using namespace std;

int menu();
int menuNuevaPartida();
string seleccionRanura();
int main()
{

    vector<Juego> juegos(1);

    int opcion = menu();
    string partida;

    do{
        switch(opcion){
        case 1:{
            partida = seleccionRanura();
            int opcionNuevaPartida = menuNuevaPartida();
            switch(opcionNuevaPartida){
            case 1:{
                int numeroJugadores=0;
                cout << "Ingrese el numero de jugadores: ";
                cin >> numeroJugadores;  /////////////////////////
                cout << endl;
                vector<Jugador> jugadores(numeroJugadores);  ////////////////////////
                for(int i=0; i<numeroJugadores; i++){
                    string nombre;
                    cout << "Ingrese el nombre del jugador " << i << ": ";
                    cin >> nombre;
                    if (i==0){
                        pair<int, int> posicionActual(0, 0);
                        jugadores[i] = Jugador(nombre, 15, i, posicionActual);
                    }
                    else if(i==1){
                        pair<int, int> posicionActual(0, 14);
                        jugadores[i] = Jugador(nombre, 15, i, posicionActual);
                    }
                    else if(i==2){
                        pair<int, int> posicionActual(14, 14);
                        jugadores[i] = Jugador(nombre, 15, i, posicionActual);
                    }
                    else if(i==3){
                        pair<int, int> posicionActual(14, 0);
                        jugadores[i] = Jugador(nombre, 15, i, posicionActual);
                    }
                }
                system("cls");
                juegos[0].setJugadores(jugadores);
                juegos[0].setDificultad("facil");
                juegos[0].setTablero(15);
                juegos[0].setJuego();
                juegos[0].setPartida(partida);
                juegos[0].jugar();

                break;
            }
            case 2:{


                int numeroJugadores=0;
                cout << "Ingrese el numero de jugadores: ";
                cin >> numeroJugadores;
                cout << endl;
                vector<Jugador> jugadores(numeroJugadores);
                for(int i=0; i<numeroJugadores; i++){
                    string nombre;
                    cout << "Ingrese el nombre del jugador " << i << ": ";
                    cin >> nombre;
                    if (i==0){
                        pair<int, int> posicionActual(0, 0);
                        jugadores[i] = Jugador(nombre, 23, i, posicionActual);
                    }
                    else if(i==1){
                        pair<int, int> posicionActual(0, 22);
                        jugadores[i] = Jugador(nombre, 23, i, posicionActual);
                    }
                    else if(i==2){
                        pair<int, int> posicionActual(22, 22);
                        jugadores[i] = Jugador(nombre, 23, i, posicionActual);
                    }
                    else if(i==3){
                        pair<int, int> posicionActual(22, 0);
                        jugadores[i] = Jugador(nombre, 23, i, posicionActual);
                    }
                }
                system("cls");
                juegos[0].setJugadores(jugadores);
                juegos[0].setDificultad("medio");
                juegos[0].setTablero(23);
                juegos[0].setJuego();
                juegos[0].setPartida(partida);
                juegos[0].jugar();
                break;
            }
            case 3:{
                int numeroJugadores=0;
                cout << "Ingrese el numero de jugadores: ";
                cin >> numeroJugadores;
                cout << endl;
                vector<Jugador> jugadores(numeroJugadores);
                for(int i=0; i<numeroJugadores; i++){
                    string nombre;
                    cout << "Ingrese el nombre del jugador " << i << ": ";
                    cin >> nombre;
                    if (i==0){
                        pair<int, int> posicionActual(0, 0);
                        jugadores[i] = Jugador(nombre, 31, i, posicionActual);
                    }
                    else if(i==1){
                        pair<int, int> posicionActual(0, 30);
                        jugadores[i] = Jugador(nombre, 31, i, posicionActual);
                    }
                    else if(i==2){
                        pair<int, int> posicionActual(30, 30);
                        jugadores[i] = Jugador(nombre, 31, i, posicionActual);
                    }
                    else if(i==3){
                        pair<int, int> posicionActual(30, 0);
                        jugadores[i] = Jugador(nombre, 31, i, posicionActual);
                    }
                }
                system("cls");
                juegos[0].setJugadores(jugadores);
                juegos[0].setDificultad("dificil");
                juegos[0].setTablero(31);
                juegos[0].setJuego();
                juegos[0].setPartida(partida);
                juegos[0].jugar();

                break;
            }
            }
        }
        case 2:{
            partida = seleccionRanura();
            string dificultad;
            int tablero;
            pair <int, int> pos;
            vector<string> datos;
            vector <Jugador> jugadores;
            int nroJugadores = 0;

            ifstream archivo(partida);
            string linea;
            int numeroLinea = 0;

            while (getline(archivo, linea)) {
                numeroLinea++;
                if (numeroLinea == 1) {
                    dificultad = linea;
                    cout<<"Entro a 1"<<endl;
                }
                else if (numeroLinea == 2) {
                    tablero = stoi(linea);
                    cout<<"Entro a 2"<<endl;
                }
                else {

                    datos.clear();

                    stringstream ss(linea);
                    string campo;

                    while (getline(ss, campo, ';')) {
                        datos.push_back(campo);
                    }

                    nroJugadores++;

                    pos.first = stoi(datos[3]);
                    pos.second = stoi(datos[4]);

                    jugadores.emplace_back(
                        datos[0], stoi(datos[1]), stoi(datos[2]), pos
                    );

                    jugadores.back().setPVActual(stoi(datos[5]));

                }
            }

            archivo.close();
                juegos[0].setJugadores(jugadores);
                juegos[0].setDificultad(dificultad);
                juegos[0].setTablero(tablero);
                juegos[0].setJuego();
                juegos[0].setPartida(partida);
                juegos[0].jugar();

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

string seleccionRanura(){
    int seleccion;
    cout<<"Seleccione el numero de ranura que desea ocupar (1-3) -> ";
    cin>>seleccion;
    while (!(1<=seleccion<=3)){
        cout<<"Eleccion errada, compruebe que haya digitado un numero del 1 al 3\n";
    }
    if (seleccion == 1){
        return "partida1.txt";
    }else if(seleccion == 2){
        return "partida2.txt";
    }else{
        return "partida3.txt";
    }
}
