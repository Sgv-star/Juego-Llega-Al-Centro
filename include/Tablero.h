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

        bool getEsEspecial(int fila, int col);
        bool getDescubierta(int fila, int col);
        int  getValor(int fila, int col);
        void descubrir(int fila, int col);


    protected:

    private:
        vector<vector<bool>> esEspecial;
        vector<vector<bool>> descubierta;
        vector<vector<int>> valor;
        int tamano;
        Casilla casillas;
        CasillaEspecial casillasEspeciales;
};

#endif // TABLERO_H
