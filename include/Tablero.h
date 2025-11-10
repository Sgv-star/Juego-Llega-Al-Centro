#ifndef TABLERO_H
#define TABLERO_H
#include <vector>
#include <utility>
#include <algorithm>
#include <Casilla.h>
#include <CasillaEspecial.h>
#include <RNG.h>
using namespace std;

class Tablero
{
    public:
        Tablero();
        Tablero(int tamano);

        void setTamano(int tamano);

        int getTamano();

    protected:

    private:
        int tamano;
        Casilla casillas;
        CasillaEspecial casillasEspeciales;
};

#endif // TABLERO_H
