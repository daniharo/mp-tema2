/**
 * @file Matriz2D.h
 * @author Daniel Haro Contreras
 * @brief Declaración de las clases Matriz2D_1 y Matriz2D_2
 * @version 0.1
 * @date 2019-04-11
 * 
 * @copyright Copyright (c) 2019
 * 
 */


/**
 * @brief Copia los datos de <origen> en <dest>
 * 
 * @param origen 
 * @param dest 
 * @param numFilas Numero de filas copiadas
 * @param numColumnas Numero de columnas copiadas
 * @param fOriIni Fila inicial en el origen (por defecto = 0)
 * @param cOriIni Columna inicial en el origen (por defecto = 0)
 * @param fDestIni Fila inicial en destino (por defecto = 0)
 * @param cDestIni Columna inicial en destino (por defecto = 0)
 */
void copiarDatos(int **origen, int **dest, int numFilas, int numColumnas, 
                 int fOriIni = 0, int cOriIni = 0, int fDestIni = 0, int cDestIni = 0);

//////////////////////////////////////////////////////////////////////////////////////////

// Declaración anticipada de los nombres de clase para poder implementar los métodos
// toMatriz2D_2 y toMatriz2D_1 en Matriz2D_1 y Matriz2D_2, respectivamente
template<typename T>
class Matriz2D_1;

template<typename T>
class Matriz2D_2;


template <typename T>
/**
 * @brief Representa una matriz 2D (ejercicio 17)
 * 
 */
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
     * @brief Destroy the Matriz2D_1 object
     * 
     */
    ~Matriz2D_1(void);

    /**
     * @brief Devuelve numero de filas
     * 
     * @return int numero de filas
     */
    int getnFilas() {return nFilas;}

    /**
     * @brief Devuelve el  numero de columnas
     * 
     * @return int numero de columnas
     */
    int getnColumnas() {return nColumnas;}

    /**
     * @brief Devuelve el valor almacenado en la pos. [fil][col]
     * 
     * @param fil 
     * @param col 
     * @return T 
     */
    T obtenerValor(int fil, int col)const
    {
        T dato = 0;
        if(fil >= 0 && fil < nFilas && col >= 0 && col < nColumnas)
            dato = datos[fil][col];
        
        return dato;
    }

    /**
     * @brief Modifica el valor almacenado en la posicion [fil][col]
     * 
     * @param fil 
     * @param col 
     * @param nuevo 
     */
    void modificar(int fil, int col, T nuevo)
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

    void copia(const Matriz2D_1<T> &otra);

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
    Matriz2D_1<T>* submatriz(int fil1, int col1, int fil2, int col2);

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

private:
    T** reservar(int , int);
};

////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////

template <typename T>
/**
 * @brief Representa una Matriz 2D (ejercicio 18)
 * 
 */
class Matriz2D_2
{
private:
    T **datos = 0;
    int nFilas;
    int nColumnas;

public:
    /**
     * @brief Construct a new Matriz2D_2 object
     * 
     * @param nf numero filas
     * @param nc numero columnas
     */
    Matriz2D_2(int nf, int nc);

    /**
     * @brief Destroy the Matriz2D_2 object
     * 
     */
    ~Matriz2D_2(void);

    /**
     * @brief Devuelve numero de filas
     * 
     * @return int 
     */
    int getnFilas() {return nFilas;}

    /**
     * @brief Devuelve numero de columnas
     * 
     * @return int 
     */
    int getnColumnas() {return nColumnas;}

    /**
     * @brief Devuelve el valor almacenado en la pos. [fil][col]
     * 
     * @param fil 
     * @param col 
     * @return T 
     */
    T obtenerValor(int fil, int col)const
    {
        T dato = 0;
        if(fil >= 0 && fil < nFilas && col >= 0 && col < nColumnas)
            dato = datos[fil][col];
        
        return dato;
    }

    /**
     * @brief Modifica el valor de datos[fil][col]
     * 
     * @param fil 
     * @param col 
     * @param nuevo nuevo valor
     */
    void modificar(int fil, int col, T nuevo)
    {
        datos[fil][col] = nuevo;
    }

    /**
     * @brief Libera la memoria en la que está almacenado el objeto
     * 
     */
    void liberar(void);

    /**
     * @brief Muestra en pantalla la información de la matriz
     * 
     */
    void mostrar(void);

    /**
     * @brief Copia el contenido de <otra> en la matriz actual
     * 
     * @param otra 
     */
    void copia(const Matriz2D_2<T> &otra);

    /**
     * @brief Devuelve una matriz igual a la actual
     * 
     * @return Matriz2D_2<T> 
     */
    Matriz2D_2<T> copia(void)const; // Constructor de copia -> Matriz2D(const Matriz2D &otra);

    /**
     * @brief Devuelve un puntero a una submatriz entre [fil1][col1] y [fil2][col2]
     * 
     * @param fil1 
     * @param col1 
     * @param fil2 
     * @param col2 
     * @return Matriz2D_2<T>* 
     */
    Matriz2D_2<T>* submatriz(int fil1, int col1, int fil2, int col2);

    /**
     * @brief Elimina la fila <filEliminada>
     * 
     * @param filEliminada 
     */
    void eliminaFila(int filEliminada);

    /**
     * @brief Elimina la columna <colEliminada>
     * 
     * @param colEliminada 
     */
    void eliminaColumna(int colEliminada);

    /**
     * @brief Devuelve un objeto de tipo Matriz2D_1 con la misma información
     * 
     * @return Matriz2D_1<T> 
     */
    Matriz2D_1<T> toMatriz2D_1(void);

private:
    /**
     * @brief Reserva espacio de memoria para el puntero a puntero <datos>
     * 
     * @return T** 
     */
    T** reservar(int, int);
};
