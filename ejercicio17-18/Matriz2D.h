#include <climits>
using namespace std;

template <typename T>
class Matriz2D_1
{
private:
    int nFilas;
    int nColumnas;
    T **datos = 0;

public:
    /**
     * @brief Construct a new Matriz2D_1 object
     * 
     * @param nf Filas del nuevo objeto
     * @param nc Columnas del nuevo objeto
     */
    Matriz2D_1(int nf, int nc);

    /**
     * @brief Devuelve numero de filas
     * 
     * @return int numero de filas
     */
    inline int getnFilas() {return nFilas;}

    /**
     * @brief Devuelve el  numero de columnas
     * 
     * @return int numero de columnas
     */
    inline int getnColumnas() {return nColumnas;}

    /**
     * @brief Devuelve el valor almacenado en la pos. [fil][col]
     * 
     * @param fil 
     * @param col 
     * @return T 
     */
    inline T obtenerValor(int fil, int col)const
    {
        T dato = INT_MIN;
        if(fil >= 0 && fila < nFilas && col >= 0 && col < nColumnas)
            dato = matriz[fil][col];
        
        return dato;
    }

    /**
     * @brief Modifica el valor almacenado en la posicion [fil][col]
     * 
     * @param fil 
     * @param col 
     * @param nuevo 
     */
    inline void modificar(int fil, int col, T nuevo)
    {
        datos[fil][col] = nuevo;
    }

    /**
     * @brief Libera el espacio de memoria reservado
     * 
     */
    void liberar(void);     // DESTRUCTOR ->  ~Matriz2D();

    /**
     * @brief Muestra en pantalla el objeto
     * 
     */
    void mostrar(void)const;

    /**
     * @brief 
     * 
     * @return Matriz2D_1<T> 
     */
    Matriz2D_1<T> copia(void)const; // Constructor de copia -> Matriz2D(const Matriz2D &otra);

    /**
     * @brief Devuelve una submatriz
     * 
     * @param fil1 
     * @param col1 
     * @param fil2 
     * @param col2 
     * @return Matriz2D_1<T> 
     */
    Matriz2D_1<T> submatriz(int fil1, int col1, int fil2, int col2);

    /**
     * @brief Elimina una fila
     * 
     * @param fil 
     */
    void eliminaFila(int fil);

    /**
     * @brief Elimina una columna
     * 
     * @param colEliminada 
     */
    void eliminaColumna(int colEliminada);

    /**
     * @brief Devuelve una copia del objeto como Matriz2D_2
     * 
     * @return Matriz2D_2<T> 
     */
    Matriz2D_2<T> toMatriz2D_2(void);
};

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