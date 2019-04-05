#include <iostream>
using namespace std;

template <typename T>
class Matriz2D_1;

template <typename T>
class Matriz2D_2;


// Definición

template <typename T>
class Matriz2D_1
{
private:
    int fils;
    int cols;
    T **datos = 0;

public:
    Matriz2D_1(int nf, int nc)
    {
        fils = nf;
        cols = nc;

        if(nf > 0 && nc > 0) {
            datos = new T*[nf];
            for(int i = 0; i < nf; i++) {
                datos[i] = new T[nc];
            }
        }
    }

    int getFils() {return fils;}

    int getCols() {return cols;}

    void modificar(int fil, int col, T nuevo)
    {
        datos[fil][col] = nuevo;
    }

    void liberar(void)
    {
        if(datos != 0) {
            for(int i = 0; i < fils; i++) {
                delete [] datos[i];
            }

            delete [] datos;
            datos = 0;

            fils = 0;
            cols = 0;
        }
    }

    void mostrar(void)
    {
        for(int i = 0; i < fils; i++) {
            cout << "Fila " << i << ": ";
            for(int j = 0; j < cols; j++) {
                cout << datos[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matriz2D_1<T> copia(void)
    {
        Matriz2D_1<T> matriz(fils, cols);

        for(int i = 0; i < fils; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                matriz.modificar(i, j, datos[i][j]);
            }
        }

        return matriz;
    }

    Matriz2D_1<T> submatriz(int fil1, int col1, int fil2, int col2)
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

    void eliminaFila(int fil)
    {
        if(fil >= 0 && fil < fils) {

            for(int i = fil; i < fils-1; i++) {
                datos[i] = datos[i+1];
            }
            datos[fils-1] = 0;
            fils--;
        }
    }

    void eliminaColumna(int colEliminada)
    {
        if(colEliminada >= 0 && colEliminada < cols) {
            for(int i = 0; i < fils; i++) {
                T *filaNueva = new T[cols-1];

                for(int j = 0, pos = 0; j < cols; j++) {
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

    Matriz2D_2<T> toMatriz2D_2(void)
    {
        Matriz2D_2<T> matriz(fils, cols);

        for(int i = 0; i < fils; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                matriz.modificar(i, j, datos[i][j]);
            }
        }

        return matriz;
    }
};

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

template <typename T>
class Matriz2D_2
{
private:
    T **datos = 0;
    int fils  = 0;
    int cols  = 0;

public:
    Matriz2D_2(int nf, int nc)
    {
        fils = nf;
        cols = nf;

        datos = new T * [nf];
        datos[0] = new T [nf*nc];

        for(int i = 1; i < nf; i++)
        {
            datos[i] = datos[i-1] + cols;
        }
    }

    int getFils() {return fils;}

    int getCols() {return cols;}

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
            fils = 0;
            cols = 0;
        }
    }

    void mostrar(void)
    {
        for(int i = 0; i < fils; i++) {
            cout << "Fila " << i << ": ";

            for(int j = 0; j < cols; j++) {
                cout << datos[i][j] << " ";
            }

            cout << endl;
        }
    }

    Matriz2D_2<T> copia(void)
    {
        Matriz2D_2<T> matriz(fils, cols);

        for(int i = 0; i < fils; i++) {
            for(int j = 0; j < cols; j++) {
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
        if(filEliminada >= 0 && filEliminada < fils) {
            int nuevoTamanio = (fils-1)*cols;
            T *nuevosDatos = new T[nuevoTamanio];

            int pos = 0;
            for(int i = 0; i < fils; i++) {
                if(i != filEliminada) {
                    for(int j = 0; j < cols; j++) {
                        nuevosDatos[pos] = datos[i][j];
                        pos++;
                    }
                }
            }

            if(datos != 0)
                delete [] datos;
            
            datos = nuevosDatos;
            fils--;
        }
    }

    Matriz2D_1<T> toMatriz2D_1(void)
    {
        Matriz2D_1<T> matriz(fils, cols);

        for(int i = 0; i < fils; i++) {
            for(int j = 0; j < cols; j++) {
                matriz.modificar(i, j, datos[cols*i + j]);
            }
        }

        return matriz;
    }
};