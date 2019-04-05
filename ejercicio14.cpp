#include <iostream>
#include <fstream>      // ficheros (ifstream -> input file stream)
using namespace std;
/**
 * @brief Inicializa el array dinámico
 * 
 * @param arraychar 
 * @param n 
 */
void inicializar(char *&arraychar, int &nCaracteres)
{
    arraychar = 0;
    nCaracteres = 0;
}

void liberar(char * &arraychar, int &nCaracteres)
{
    if(arraychar){
        delete [] arraychar;
        arraychar = 0;
    }
    nCaracteres = 0;
}

void mostrar (ostream &flujo, const char cad[], int nCaracteres)
{
    flujo << "Contenido del array: ";
    for(int i = 0; i < nCaracteres; i++)
        flujo << cad[i];
    flujo << endl;
}

void redimensionar(char *&arraychar, int nCaracteres, int aumento)
{
    char *ptrNew = new char[nCaracteres+aumento];

    for(int i = 0; i < nCaracteres; i++)
        ptrNew[i] = arraychar[i];
    
    // No nos preocupamos de nCaracteres ya que el paso es por valor
    liberar(arraychar, nCaracteres);
    
    arraychar = ptrNew;
}

void aniadir(char *&arraychar, int &nCaracteres, char aniadido)
{
    redimensionar(arraychar, nCaracteres, 1);
    arraychar[nCaracteres] = aniadido;
    nCaracteres++;
}

void leer(istream &flujo, char *&array, int &nCaracteres)
{
    char caracter;
    while (flujo.get(caracter))
    {
        aniadir(array, nCaracteres, caracter);
    }
}

int main(int argc, char * argv[])   // argc = "argument counter"
                                    // argv = "argument vector"
{
    char *arraychar;
    int nCaracteres;
    inicializar(arraychar, nCaracteres);

    if (argc == 1)
        leer(cin, arraychar, nCaracteres);
    else
    {
        ifstream flujo(argv[1]);
        if (!flujo) // Si el archivo no existe (flujo = objeto nulo)
        {
            cerr << "Error: Fichero " << argv[1] << " no valido." << endl;
            return 1;
        }
        leer(flujo, arraychar, nCaracteres);
    }

    mostrar(cout, arraychar, nCaracteres);
    liberar(arraychar, nCaracteres); // Libera la memoria dinámica reservada

    return (0);
}