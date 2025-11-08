#ifndef RNG_H
#define RNG_H
#include <random>

using namespace std;

class RNG
{
    public:
        RNG();
        RNG(int valorMaximo=0);
        void setValorMaximo(int valorMaximo);
        int getValorMaximo();
        int getRandom();

    protected:

    private:
        mt19937 rng;
        uniform_int_distribution<int> dist;
        int valorMaximo;
};

#endif // RNG_H
