#include "Tablero.h"

Tablero::Tablero()
{
    //ctor
}
int Tablero::getTamano(){
    return tamano;
}

bool Tablero::getDescubierta(int fila, int col)
{
    return descubierta[fila][col];
}

int Tablero::getValor(int fila, int col)
{
    return valor[fila][col];
}

void Tablero::descubrir(int fila, int col)
{
    descubierta[fila][col] = true;
}


void Tablero::setTamano(int tamano){
    this -> tamano = tamano;
}


bool Tablero::getEsEspecial(int fila, int col)
{
    return esEspecial[fila][col];
}


Tablero::Tablero(int tamano){
    this->tamano = tamano;

    // 1. Inicializar las matrices miembro con el tamaño correcto
    esEspecial.assign(tamano, vector<bool>(tamano, false));
    descubierta.assign(tamano, vector<bool>(tamano, false));
    valor.assign(tamano, vector<int>(tamano, 0));

    int casillasTotales = tamano * tamano;

    // 2. RNG para el porcentaje
    RNG rngPorcentaje = RNG(10);

    int porcentaje = rngPorcentaje.getRandom();  // 1..10
    if (porcentaje < 6){
        porcentaje = 6;  // mínimo 6%
    }

    // OJO: multiplica primero, luego divide
    int cantidadCasillasEspeciales = casillasTotales * porcentaje / 100;
    if (cantidadCasillasEspeciales == 0) cantidadCasillasEspeciales = 1;

    // 3. Generar todas las posiciones posibles
    vector<pair<int, int>> posiciones;
    posiciones.reserve(casillasTotales);

    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano; j++) {
            posiciones.push_back({i, j});
        }
    }

    // 4. Mezclar posiciones
    mt19937 motor(random_device{}());
    shuffle(posiciones.begin(), posiciones.end(), motor);

    // 5. Elegir las primeras N como especiales y asignar valores
    RNG rngValor = RNG(tamano);   // valores 1..tamano por ejemplo

    for (int i = 0; i < cantidadCasillasEspeciales; i++) {
        int x = posiciones[i].first;
        int y = posiciones[i].second;

        esEspecial[x][y] = true;
        descubierta[x][y] = false;

        int v = rngValor.getRandom();  // 1..tamano

        // mitad recompensa (+v), mitad castigo (-v)
        if (i % 2 == 0) {
            valor[x][y] = v;
        } else {
            valor[x][y] = -v;
        }
    }
}
