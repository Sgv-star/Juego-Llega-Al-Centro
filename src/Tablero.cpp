#include "Tablero.h"

Tablero::Tablero()
{
    //ctor
}

Tablero::Tablero(int tamano){
    Casilla tablero[tamano][tamano];
    int casillasTotales = tamano * tamano;

    //Se instancia un rng para ayudar a calcular aleatoriamente el porcentaje de casillas especiales
    RNG rngPorcentaje = RNG(10);

    //Calcular un numero del entre el 1 al 10 (y luego se reduce del 6 al 10) para definir el porcentaje
    int porcentaje = rngPorcentaje.getRandom();
    if (porcentaje < 6){
        porcentaje = 6;
    }

    //Se calcula la cantidad de casillas que van a ser casillas especiales segun el porcentaje calculado
    int cantidadCasillasEspeciales = casillasTotales * (porcentaje/100);

    //Se almacenan todos los pares de coordenadas del tablero en un vector
    vector<pair<int, int>> posiciones;
    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano; j++) {
            posiciones.push_back({i, j});
        }
    }

    //Organizar aleatoriamente los pares de coordenadas en una
    mt19937 motor(rngPorcentaje.getRandom());
    shuffle(posiciones.begin(), posiciones.end(), motor);

    //Se asignan las casillas especiales a las primeras posiciones de la lista de coordenadasm recorriendo cada posicion del vector y llamando a cada posicion x y y con .first y .second
    for (int i = 0; i < cantidadCasillasEspeciales; i++) {
        int x = posiciones[i].first;
        int y = posiciones[i].second;
        tablero[x][y] = CasillaEspecial();
    }

    //Se rellena el resto del tablero con casillas normales, recorriendo la lista de coordenadas aleatorizadas desde la ultima casilla especial
    for (int i = cantidadCasillasEspeciales; i < posiciones.size(); i++) {
        int x = posiciones[i].first;
        int y = posiciones[i].second;
        tablero[x][y] = Casilla();
    }
}

void Tablero::setTamano(int tamano){
    this -> tamano = tamano;
}

int Tablero::getTamano(){
    return tamano;
}
