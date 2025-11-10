#ifndef JUGADOR_H
#define JUGADOR_H
#include <string>

using namespace std;

class Jugador
{
    public:
        Jugador();
        Jugador(string nombre, int PVInicial, int numeroJugador, pair<int, int> posicionActual);

        void setNombre(string nombre);
        void setPVInicial(int PVInicial);
        void setPVActual(int PVActual);
        void setNumeroJugador(int numeroJugador);
        void setEstado(bool estado);
        void setPosicionActual(pair<int, int> posicionActual);

        string getNombre();
        int getPVInicial();
        int getPVActual();
        int getNumeroJugador();
        bool getEstado();
        pair<int, int> getPosicionActual();

    protected:

    private:
        string nombre;
        int PVInicial;
        int PVActual;
        int numeroJugador;
        bool estado;
        pair<int, int> posicionActual;
};

#endif // JUGADOR_H
