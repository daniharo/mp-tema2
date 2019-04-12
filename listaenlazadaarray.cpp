// LISTA ENLAZADA donde cada celda contiene un array dinámico
// (Examen junio 2006)

#include <cstring>


class Celda
{
    int *datos;
    Celda *sig;

public:
    Celda(void)
    {
        datos = nullptr;
        sig = nullptr;
    }
};

class Imagen
{
    Celda *imag;
    int numeroFilas;
    int numeroColumnas;
public:
    Imagen(void)
    {
        imag = nullptr;
        numeroFilas = 0;
        numeroColumnas = 0;
    }
};

//////////////////////////////////////////////////////////////////////////////
// Septiembre 2017

struct Cadena
{
    char *cad;  // array de caracteres, centinela='\0' -> cadena estilo C

    // (datos públicos y métodos)
    Cadena()
    {
        cad = nullptr;
        // Otra opción:
        // cad = new char[100];
    }

    Cadena(char *contenido)
    {
        cad = new char[strlen(contenido)+1];
        strcpy(cad, contenido);
    }

    void asignar(char *contenido)
    {
        if(!cad) {
            cad  = new char[strlen(contenido) +1];
        }

        strcpy(cad, contenido);
    }
};

class Conjunto
{
    Cadena *cadena; // array de objetos de tipo Cadena
    int numero;     // tamaño del array

public:
    Conjunto()
    {
        cadena = nullptr;
        numero = 0;
    }

    Conjunto(int numCadenas, char *cadenas[])
    {
        numero = numCadenas;
        cadena = new Cadena[numero];

        for(int i = 0; i < numCadenas; i++)
        {
            strcpy(cadena[i].cad, cadenas[i]);
        }
    }
};


///////////////////////////////////////////////////////////////
// Septiembre 2012: Matriz2D_1

class Matriz
{
private:
    int nFilas;
    int *nColumnas;     // Cada fila puede tener un número distinto de columnas

    double **datos;

public:

    Matriz(int nFilas, int nColumnas[])
    {
        this->nFilas = nFilas;
        nColumnas = new int[nFilas];
        datos = new double*[nFilas];

        for(int i = 0; i < nFilas; i++) {
            this->nColumnas[i] = nColumnas[i];
            datos[i] = new double[nColumnas[i]];
        }
    }

    ~Matriz(void)
    {
        if(datos)
            liberar();
    }

    void liberar()
    {
        for(int i = 0; i < nFilas; i++)
        {
            delete [] datos[i];
        }

        delete [] nColumnas;
        delete [] datos;
    }
};



////////////////////////////////////////////////////////////////////////////

struct Punto
{
    double x, y;
    // NO NECESARIO implementar destructores, constructor de copia...
    // porque no tiene gestión dinámica de memoria
};

class Polilinea
{
    Punto *puntos;
    int numeroVertices;
    int espacioReservado;
}