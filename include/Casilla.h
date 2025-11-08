#ifndef CASILLA_H
#define CASILLA_H


class Casilla
{
    public:
        Casilla();
        Casilla(int fila, int columna);

        void setFila(int fila);
        void setColumna(int columna);
        void setEsCasillaCentral(bool esCasillaCentral);

        int getFila();
        int getColumna();
        bool getEsCasillaCentral();


    protected:

    private:
        int fila;
        int columna;
        bool esCasillaCentral;
};

#endif // CASILLA_H
