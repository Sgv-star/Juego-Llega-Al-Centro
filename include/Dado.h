#ifndef DADO_H
#define DADO_H
#include <RNG.h>

using namespace std;

class Dado
{
    public:
        Dado();
        Dado(int PVMaximo);
        int sacarNumero();
        void setPVMaximo(int PVMaximo);
        int getPVMaximo();

    protected:

    private:
        int PVMaximo;
};

#endif // DADO_H
