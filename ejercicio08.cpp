#include <iostream>
#include <cmath>
#include "utilarray.h"
using namespace std;

void swap(int *a, int *b)
{
    int *tmp = a;
    a = b;
    b = tmp;
}

int ordenCreciente(int l, int r)
{
    return l-r;
}

int ordenDecreciente(int l, int r)
{
    return r-l;
}

void ordenacionPorBurbuja(const int array[], int utilArray, const int *ord[], int (*orden)(int, int))
{
    for(int i = 0; i < utilArray; i++)
        ord[i] = array+i;

    for(int i = utilArray-1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if((*orden)(*ord[j], *ord[j+1]) < 0) {
                swap(ord[j], ord[j+1]);
            }
        }
    }
}

int main()
{
    // Mostrar todos los elementos ordenados

    const int TAM = 1000;
    int vec[TAM];
    const int *ptr[TAM];

    int util = leerArray(vec, TAM);
    ordenacionPorBurbuja(vec, util, ptr, ordenCreciente);

    cout<< "Ordenados: " << endl;
    for(int i = 0; i < util; i++) {
        cout << *ptr[i] << " ";
    }

    // Mostrar elementos de la segunda mitad ordenados

    int *ptrSegMitad = &vec[util/2];
    const int *ptr2[TAM];
    int util2 = ceil(util/2.0);

    ordenacionPorBurbuja(ptrSegMitad, util2, ptr2, ordenCreciente);

    cout << endl << "Elementos de la segunda mitad del array ordenados:" << endl;
    for(int i = 0; i < util2; i++) {
        cout << *ptr2[i] << " ";
    }

    return 0;
}