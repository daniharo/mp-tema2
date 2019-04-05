#include <iostream>
#include <fstream>   // ifstream
#include <string.h>
using namespace std;

struct ListaCadenas 
{
    char** cadenas;
    int nCads;
};

void crear(ListaCadenas&);
void imprimir(ostream&, const ListaCadenas&);
void redimensionar(ListaCadenas&, int);
void aniadir(ListaCadenas&, int);
void leer(istream&, ListaCadenas&);
void liberar(ListaCadenas&);
void ordenar(ListaCadenas&);

int main(int argc, char* argv[])
{
    ListaCadenas lista;
    crear(lista);
    if (argc == 1)
        leer(cin, lista);
    else
    {
        ifstream f(argv[1]);
        if (!f)
        {
            cerr << "Error: Fmostrarichero " << argv[1] << " no v´alido." << endl;
            return 1;
        }
        leer(f, lista);
    }
    cout << "Original:" << endl;
    imprimir(cout, lista);
    ordenar(lista);
    cout << "\nResultado:" << endl;
    imprimir(cout, lista);
    liberar(lista); // Libera la memoria din´amica reservada
}

void crear(ListaCadenas& listaCadenas)
{
    listaCadenas.cadenas = 0;
    listaCadenas.nCads = 0;
}

void imprimir(ostream& flujo, const ListaCadenas& listaCadenas)
{
    for(int i = 0; i < listaCadenas.nCads; i++) {
        flujo << "Cadena " << i << ": " << listaCadenas.cadenas[i] << endl;
    }
}

void redimensionar(ListaCadenas& listaCadenas, int newSize)
{
    if(listaCadenas.nCads != newSize) {
        if(newSize != 0) {
            char **newLista = new char*[newSize];
        
            int minimo = newSize < listaCadenas.nCads ? newSize : listaCadenas.nCads;

            if(listaCadenas.nCads > 0) {

                for(int i = 0; i < minimo; i++)
                    newLista[i] = listaCadenas.cadenas[i];
                
                liberar(listaCadenas);
                
            }

            for(int i = minimo; i < newSize; i++)
                newLista[i] = 0;

            listaCadenas.cadenas = newLista;
            listaCadenas.nCads = newSize;
        }

        else {
            liberar(listaCadenas);
        }
    }
}

void aniadir(ListaCadenas& listaCadenas, const char* cadena)
{
    int longCad = strlen(cadena);

    redimensionar(listaCadenas, listaCadenas.nCads+1);
    listaCadenas.cadenas[listaCadenas.nCads-1] = new char[longCad+1];
    strcpy(listaCadenas.cadenas[listaCadenas.nCads-1], cadena);
}

void leer(istream &flujo, ListaCadenas &listaCadenas)
{
    const int NCARACTERES = 1000; // Suponemos líneas con menos de 1000 char
    char linea[NCARACTERES];
    while (flujo.getline(linea, NCARACTERES))
    {
        aniadir(listaCadenas, linea);
    }
}

void liberar(ListaCadenas& listaCadenas)
{
    delete [] listaCadenas.cadenas;
    listaCadenas.cadenas = 0;
    listaCadenas.nCads = 0;
}

/**
 * @brief Compara la relación de orden entre dos cadenas de caracteres
 * 
 * @param cad1 
 * @param cad2 
 * @return true Si la primera cadena es mayor que la segunda
 * @return false En otro caso
 */
bool esMayor (const char cad1[], const char cad2[])
{
    bool encontrado = false;
    bool mayor = false;

    for(int i = 0, j = 0; (cad1[i] != '\0') && (cad2[j] != '\0') && !encontrado; i++, j++)
    {
        // Primero saltamos los espacios
        while(cad1[i] == ' ' || cad1[i] == ',')
            i++;
        while(cad2[j] == ' ' || cad2[j] == ',')
            j++;
        
        // Comprobamos el orden, y si son iguales se continúa
        if(cad1[i] > cad2[j]) {
            encontrado = true;
            mayor = true;
        }
        else if(cad1[i] < cad2[j]) {
            encontrado = true;
        }
    }

    // Si no se ha encontrado cuál es la mayor, se compara la longitud
    if(!encontrado)
        mayor = strlen(cad1) > strlen(cad2);

    return (mayor);
}

void copiaCad(char *&dest, char *&src)
{
    if(dest != 0)
        delete [] dest;
    
    dest = new char[strlen(src)+1];
    strcpy(dest, src);
}

/**
 * @brief Busca la cadena mínima (menor en el orden alfabético) en una lista de cadenas
 * 
 * @param listaCadenas lista de cadenas
 * @param posIni posición de inicio de la búsqueda
 * @param posFin posición de fin de la búsqueda
 * @return int posición del mínimo
 */
int buscaMinimaCadena(const ListaCadenas& listaCadenas, int posIni, int posFin)
{
    int posMin = posIni;

    for(int i = posIni; i <= posFin; i++)
    {
        if(esMayor(listaCadenas.cadenas[posMin], listaCadenas.cadenas[i])) {
            posMin = i;
        }
    }

    return (posMin);
}

/**
 * @brief Intercambia el valor de dos cadenas de caracteres
 * 
 * @param cad1 
 * @param cad2 
 */
void swap(char *&cad1, char *&cad2)
{
    char *tmp = 0;
    copiaCad(tmp, cad1);
    copiaCad(cad1, cad2);
    copiaCad(cad2, tmp);
    delete [] tmp;
}

/**
 * @brief Ordena un array de cadenas de caracteres según el orden alfabético
 * 
 * @param cadenas array de cadenas
 * @param nCadenas número de cadenas almacenadas en el array
 */
void ordenar(ListaCadenas& listaCadenas)
{
    for(int i = 0; i < listaCadenas.nCads-1; i++)
    {
        swap(listaCadenas.cadenas[buscaMinimaCadena(listaCadenas, i, listaCadenas.nCads-1)], 
             listaCadenas.cadenas[i]);
    }
}