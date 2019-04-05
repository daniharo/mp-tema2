#include <iostream>
using namespace std;

struct Punto2D{
    double x;
    double y;
};

struct Nodo{
    Punto2D punto;
    Nodo *sigPunto;
};

class Poligono{
    Nodo* poligono;

public:

    Poligono(Punto2D a, Punto2D b, Punto2D c)
    {
        poligono->punto = a;
        poligono->sigPunto = new Nodo;
        poligono->sigPunto->punto = b;
        poligono->sigPunto->sigPunto = new Nodo;
        poligono->sigPunto->sigPunto->punto = c;
        poligono->sigPunto->sigPunto->sigPunto = poligono;
    }

    int getLados(void)
    {
        int nLados = 1;
        Nodo *cursor = poligono->sigPunto;

        while(cursor != poligono) {
            cursor = cursor->sigPunto;
            nLados++;
        }

        return nLados;
    }

    void pintar(void)
    {
        Nodo *cursor = poligono;

        while(cursor->sigPunto != poligono) {
            pintaRecta(cursor->punto, cursor->sigPunto->punto);
            cursor = cursor->sigPunto;
        }

        pintaRecta(cursor->punto, poligono->punto);
    }

    void liberar(void)
    {
        
    }

};

void pintaRecta(Punto2D p1, Punto2D p2);

