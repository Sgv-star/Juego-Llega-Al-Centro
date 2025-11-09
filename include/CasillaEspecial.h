#ifndef CASILLAESPECIAL_H
#define CASILLAESPECIAL_H
#include <Casilla.h>
#include <RNG.h>
#include <string>

using namespace std;

class CasillaEspecial: public Casilla
{
    public:
        CasillaEspecial();
        CasillaEspecial(int PVMaximo);

        void setTipo(string tipo);
        void setDescubierta(bool descubierta);

        string getTipo();
        bool getDescubierta();

    protected:

    private:
        string tipo;
        bool descubierta;
        int valor;
};

#endif // CASILLAESPECIAL_H
