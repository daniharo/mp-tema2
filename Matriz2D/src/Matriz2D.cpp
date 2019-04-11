/**
 * @file Matriz2D.cpp
 * @author Daniel Haro Contreras
 * @brief Definición de las clases Matriz2D_1 y Matriz2D_2
 * @version 0.1
 * @date 2019-04-11
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include <iostream>
#include "Matriz2D.h"
using namespace std;


void copiarDatos(int **origen, int **dest, int numFilas, int numColumnas, 
                 int fOriIni, int cOriIni, int fDestIni, int cDestIni)
{
    for(int i = 0, iOr = fOriIni, iDest = fDestIni; i < numFilas; i++, iOr++, iDest++)
    {
        for(int j = 0, jOr = cOriIni, jDest = cDestIni; j < numColumnas; j++, jOr++, jDest++)
        {
            dest[iDest][jDest] = origen[iOr][jOr];
        }
    }
}

///////////////////////////////////////////////////////////////////////////
// Métodos de Matriz2D_1

template<typename T>
Matriz2D_1<T>::Matriz2D_1(int nFilas, int nColumnas)
{
    this->nFilas = nFilas;
    this->nColumnas = nColumnas;

    // Reservar espacio
    datos = reservar(nFilas, nColumnas);
}

template<typename T>
void Matriz2D_1<T>::liberar(void)
{
    if(datos) {
        for(int i = 0; i < nFilas; i++) {
            delete [] datos[i];
        }

        delete [] datos;
        datos = 0;
    }
}

template <typename T>
Matriz2D_1<T>::~Matriz2D_1()
{
    if(datos)
        liberar();
}

template<typename T>
void Matriz2D_1<T>::mostrar(void)const
{
    for(int i = 0; i < nFilas; i++) 
    {
        cout << "Fila " << i << ": ";
        for(int j = 0; j < nColumnas; j++) {
            cout << datos[i][j] << " ";
        }
        cout << endl;
    }
}

template <typename T>
void Matriz2D_1<T>::copia(const Matriz2D_1<T> &otra)
{
    liberar();
    nFilas = otra.nFilas;
    nColumnas = otra.nColumnas;

    // Reservar espacio
    datos = reservar(nFilas, nColumnas);

    // Copiar datos
    copiarDatos(otra.datos, datos, nFilas, nColumnas);
}

template<typename T>
Matriz2D_1<T> Matriz2D_1<T>::copia(void)const
{
    // Crear el objeto a devolver
    Matriz2D_1<T> matriz(nFilas, nColumnas);

    copiarDatos(datos, matriz.datos, nFilas, nColumnas);

    return matriz;
}

template<typename T>
Matriz2D_1<T>* Matriz2D_1<T>::submatriz(int filaIni, int colIni, int filaFin, int colFin)
{
    Matriz2D_1 *resultado = 0;

    // Comprobar la validez de los argumentos
    if(filaIni < nFilas && colIni < nColumnas && 
       filaFin < nFilas && colFin < nColumnas &&
       filaIni >= 0 && colIni >= 0 &&
       filaFin >= 0 && colFin >= 0 &&
       filaFin >= filaIni && colFin >= colIni)
    {
        resultado = new Matriz2D_1<T>(filaFin-filaIni+1, colFin-colIni+1);

        // Copiar datos de la matriz
        copiarDatos(datos, resultado->datos, resultado->nFilas, resultado->nColumnas, filaIni, colIni);
    }

    return resultado;
}

template<typename T>
void Matriz2D_1<T>::eliminaFila(int fil)
{
    if(fil >= 0 && fil < nFilas) 
    {
        T **matrizNueva = reservar(nFilas-1, nColumnas);

        // Copia filas previas
        copiarDatos(datos, matrizNueva, fil, nColumnas);

        // Copia filas posteriores
        copiarDatos(datos, matrizNueva, nFilas-fil-1, nColumnas, fil+1, 0, fil, 0);

        // Liberar el espacio ocupado anteriormente y actualizar el puntero datos
        liberar();
        datos = matrizNueva;
        nFilas--;
    }
}

template<typename T>
void Matriz2D_1<T>::eliminaColumna(int colEliminada)
{
    if(colEliminada >= 0 && colEliminada < nColumnas) 
    {
        T **matrizNueva = reservar(nFilas, nColumnas-1);

        // Copia columnas previas
        copiarDatos(datos, matrizNueva, nFilas, colEliminada);

        // Copia columnas posteriores
        copiarDatos(datos, matrizNueva, nFilas, nColumnas-colEliminada-1, 0, colEliminada+1, 0, colEliminada);

        liberar();
        datos = matrizNueva;
        nColumnas--;
    }
}

template <typename T>
Matriz2D_2<T> Matriz2D_1<T>::toMatriz2D_2(void)
{
    Matriz2D_2<T> nuevaMatriz(nFilas, nColumnas);

    // NO se puede usar el método copiarDatos ya que NO se puede acceder
    // al puntero <datos>
    for(int i = 0; i < nFilas; i++) {
        for(int j = 0; j < nColumnas; j++) {
            nuevaMatriz.modificar(i, j, datos[i][j]);
        }
    }

    return nuevaMatriz;
}

template <typename T>
T** Matriz2D_1<T>::reservar(int numFilas, int numColumnas)
{
    T ** espacio = new T*[numFilas];

    for(int i = 0; i < numFilas; i++){
        espacio[i] = new T[numColumnas];
    }

    return espacio;
}


////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
// Métodos de Matriz2D_2

template <typename T>
Matriz2D_2<T>::Matriz2D_2(int nf, int nc)
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

template <typename T>
Matriz2D_2<T>::~Matriz2D_2(void)
{
    if(datos)
        liberar();
}

template <typename T>
void Matriz2D_2<T>::liberar(void)
{
    if(datos) {
        delete [] datos[0];
        delete [] datos;

        datos = 0;
    }
}

template <typename T>
void Matriz2D_2<T>::mostrar(void)
{
    for(int i = 0; i < nFilas; i++) {
        cout << "Fila " << i << ": ";

        for(int j = 0; j < nColumnas; j++) {
            cout << datos[i][j] << " ";
        }

        cout << endl;
    }
}

template <typename T>
void Matriz2D_2<T>::copia(const Matriz2D_2<T> &otra)
{
    liberar();
    nFilas = otra.nFilas;
    nColumnas = otra.nColumnas;

    // Reservar espacio
    datos = reservar(nFilas, nColumnas);

    // Copiar datos
    copiarDatos(otra.datos, datos, nFilas, nColumnas);
}

template<typename T>
Matriz2D_2<T> Matriz2D_2<T>::copia(void)const
{
    Matriz2D_2<T> matriz(nFilas, nColumnas);

    copiarDatos(datos, matriz.datos, nFilas, nColumnas);

    return matriz;
}

template<typename T>
Matriz2D_2<T>* Matriz2D_2<T>::submatriz(int filaIni, int colIni, int filaFin, int colFin)
{
    Matriz2D_2 *resultado = 0;

    // Comprobar la validez de los argumentos
    if(filaIni < nFilas && colIni < nColumnas && 
       filaFin < nFilas && colFin < nColumnas &&
       filaIni >= 0 && colIni >= 0 &&
       filaFin >= 0 && colFin >= 0 &&
       filaFin >= filaIni && colFin >= colIni)
    {
        resultado = new Matriz2D_2<T>(filaFin-filaIni+1, colFin-colIni+1);

        // Copiar datos de la matriz

        copiarDatos(datos, resultado->datos, resultado->nFilas, resultado->nColumnas, filaIni, colIni);
    }

    return resultado;
}

template<typename T>
void Matriz2D_2<T>::eliminaFila(int fil)
{
    
    if(fil >= 0 && fil < nFilas) 
    {
        T **matrizNueva = reservar(nFilas-1, nColumnas);

        // Copia filas previas
        copiarDatos(datos, matrizNueva, fil, nColumnas);

        // Copia filas posteriores
        copiarDatos(datos, matrizNueva, nFilas-fil-1, nColumnas, fil+1, 0, fil, 0);

        liberar();
        datos = matrizNueva;
        nFilas--;
    }
}

template<typename T>
void Matriz2D_2<T>::eliminaColumna(int colEliminada)
{
    if(colEliminada >= 0 && colEliminada < nColumnas) 
    {
        T **matrizNueva = reservar(nFilas, nColumnas-1);

        // Copia columnas previas
        copiarDatos(datos, matrizNueva, nFilas, colEliminada);

        // Copia columnas posteriores
        copiarDatos(datos, matrizNueva, nFilas, nColumnas-colEliminada-1, 0, colEliminada+1, 0, colEliminada);

        liberar();
        datos = matrizNueva;
        nColumnas--;
    }
}

template <typename T>
Matriz2D_1<T> Matriz2D_2<T>::toMatriz2D_1(void)
{
    Matriz2D_1<T> nuevaMatriz(nFilas, nColumnas);

    for(int i = 0; i < nFilas; i++) {
        for(int j = 0; j < nColumnas; j++) {
            nuevaMatriz.modificar(i, j, datos[i][j]);
        }
    }

    return nuevaMatriz;
}

template <typename T>
T** Matriz2D_2<T>::reservar(int numFilas, int numColumnas)
{
    T **espacio = new T * [numFilas];
    espacio[0] = new T [numFilas*numColumnas];

    for(int i = 1; i < numFilas; i++)
    {
        espacio[i] = espacio[i-1] + numColumnas;
    }

    return espacio;
}



// CREAR EL CÓDIGO DE LAS CLASES PARA ENTEROS

template class Matriz2D_1<int>;
template class Matriz2D_2<int>;