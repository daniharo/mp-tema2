#include <iostream>
#include "Matriz2D.h"
using namespace std;

template<typename T>
Matriz2D_1<T>::Matriz2D_1(int nFilas, int nColumnas)
{
    this->nFilas = nFilas;
    this->nColumnas = nColumnas;

    // Crear el array de punteros a filas
    datos = new T*[nFilas];
    for(int i = 0; i < nFilas; i++) {
        datos[i] = new T[nColumnas];
    }
}

template<typename T>
void Matriz2D_1<T>::liberar(void)
{
    if(datos != 0) {
        for(int i = 0; i < nFilas; i++) {
            delete [] datos[i];
        }

        delete [] datos;
        datos = 0;

        nFilas = 0;
        nColumnas = 0;
    }
}

template<typename T>
void Matriz2D_1<T>::mostrar(void)const
{
    for(int i = 0; i < nFilas; i++) {
        cout << "Fila " << i << ": ";
        for(int j = 0; j < nColumnas; j++) {
            cout << datos[i][j] << " ";
        }
        cout << endl;
    }
}

template<typename T>
Matriz2D_1<T> Matriz2D_1<T>::copia(void)const
{
    Matriz2D_1<T> matriz(nFilas, nColumnas);

    for(int i = 0; i < nFilas; i++)
    {
        for(int j = 0; j < nColumnas; j++)
        {
            matriz.modificar(i, j, datos[i][j]);
        }
    }

    return matriz;
}

template<typename T>
Matriz2D_1<T> Matriz2D_1<T>::submatriz(int fil1, int col1, int fil2, int col2)
{
    Matriz2D_1<T> matriz(fil2-fil1+1, col2-col1+1);

    for(int i = fil1; i <= fil2; i++)
    {
        for(int j = col1; j <= col2; j++)
        {
            matriz.modificar(i, j, datos[i][j]);
        }
    }

    return matriz;
}

template<typename T>
void Matriz2D_1<T>::eliminaFila(int fil)
{
    if(fil >= 0 && fil < nFilas) {

        for(int i = fil; i < nFilas-1; i++) {
            datos[i] = datos[i+1];
        }
        datos[nFilas-1] = 0;
        nFilas--;
    }
}

template<typename T>
void Matriz2D_1<T>::eliminaColumna(int colEliminada)
{
    if(colEliminada >= 0 && colEliminada < nColumnas) {
        for(int i = 0; i < nFilas; i++) {
            T *filaNueva = new T[nColumnas-1];

            for(int j = 0, pos = 0; j < nColumnas; j++) {
                if(j != colEliminada) {
                    filaNueva[pos] = datos[i][j];
                    pos++;
                }
            }
            
            delete [] datos[i];

            datos[i] = filaNueva;
        }
    }
}

template<typename T>
Matriz2D_2<T> Matriz2D_1<T>::toMatriz2D_2(void)
{
    Matriz2D_2<T> matriz(nFilas, nColumnas);

    for(int i = 0; i < nFilas; i++)
    {
        for(int j = 0; j < nColumnas; j++)
        {
            matriz.modificar(i, j, datos[i][j]);
        }
    }

    return matriz;
}


////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

template <typename T>
class Matriz2D_2
{
private:
    T **datos = 0;
    int nFilas  = 0;
    int nColumnas  = 0;

public:
    Matriz2D_2(int nf, int nc)
    {
        nFilas = nf;
        nColumnas = nf;

        datos = new T * [nf];
        datos[0] = new T [nf*nc];

        for(int i = 1; i < nf; i++)
        {
            datos[i] = datos[i-1] + nColumnas;
        }
    }

    int getnFilas() {return nFilas;}

    int getnColumnas() {return nColumnas;}

    void modificar(int fil, int col, T nuevo)
    {
        datos[fil][col] = nuevo;
    }

    void liberar(void)
    {
        if(datos != 0) {
            delete [] datos[0];
            delete [] datos;
            datos = 0;
            nFilas = 0;
            nColumnas = 0;
        }
    }

    void mostrar(void)
    {
        for(int i = 0; i < nFilas; i++) {
            cout << "Fila " << i << ": ";

            for(int j = 0; j < nColumnas; j++) {
                cout << datos[i][j] << " ";
            }

            cout << endl;
        }
    }

    Matriz2D_2<T> copia(void)
    {
        Matriz2D_2<T> matriz(nFilas, nColumnas);

        for(int i = 0; i < nFilas; i++) {
            for(int j = 0; j < nColumnas; j++) {
                matriz.modificar(i, j, datos[i][j]);
            }
        }

        return matriz;
    }

    Matriz2D_2<T> submatriz(int fil1, int col1, int fil2, int col2)
    {
        Matriz2D_2<T> matriz(fil2-fil1+1, col2-col1+1);

        for(int i = fil1; i <= fil2; i++)
        {
            for(int j = col1; j <= col2; j++)
            {
                matriz.modificar(i, j, datos[i][j]);
            }
        }

        return matriz;
    }

    void eliminaFila(int filEliminada)
    {
        if(filEliminada >= 0 && filEliminada < nFilas) {
            int nuevoTamanio = (nFilas-1)*nColumnas;
            T *nuevosDatos = new T[nuevoTamanio];

            int pos = 0;
            for(int i = 0; i < nFilas; i++) {
                if(i != filEliminada) {
                    for(int j = 0; j < nColumnas; j++) {
                        nuevosDatos[pos] = datos[i][j];
                        pos++;
                    }
                }
            }

            if(datos != 0)
                delete [] datos;
            
            datos = nuevosDatos;
            nFilas--;
        }
    }

    Matriz2D_1<T> toMatriz2D_1(void)
    {
        Matriz2D_1<T> matriz(nFilas, nColumnas);

        for(int i = 0; i < nFilas; i++) {
            for(int j = 0; j < nColumnas; j++) {
                matriz.modificar(i, j, datos[nColumnas*i + j]);
            }
        }

        return matriz;
    }
};