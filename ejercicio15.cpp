#include <iostream>
#include <fstream>
using namespace std;

class VectorSD
{
private:

    int *info;
    int util;
    int reservado;

    /**
     * @brief Número de componentes reservadas inicialmente
     * por el constructor por defecto
     * 
     */
    static const int INIC_RESERV = 10;

public:

    /**
     * @brief Constructor sin parámetros, inicializa
     * el objeto reservando 10 casillas de memoria dinámica
     * y pone el número de componentes usadas a 0.
     * 
     */
    VectorSD(): info(new int[INIC_RESERV]), util(0), reservado(INIC_RESERV) {}

    /**
     * @brief Constructor que inicializa el objeto reservando
     * n casillas de memoria dinámica y pone el número de componentes
     * usadas a 0.
     * 
     * @param n 
     */
    VectorSD(int n): info(new int[n]), util(0), reservado(n) {}

    int getDato(int pos)const;
    int nElementos()const {return util;}
    void aniadir(int);
    void copia(const VectorSD&);
    void liberar();
    void mostrar(ostream&)const;
    void leer(istream&);
};

/*****************************************************************************/

int main(int argc, char* argv[])
{
    VectorSD v;
    if (argc == 1)
        v.leer(cin);
    else
    {
        ifstream flujo(argv[1]);
        if (!flujo)
        {
            cerr << "Error: Fichero " << argv[1] << " no valido." << endl;
            return 1;
        }
        v.leer(flujo);
    }
    v.mostrar(cout);
    v.liberar(); // Libera la memoria dinámica reservada
}

/****************************************************************************/

int VectorSD::getDato(int pos) const
{
    // Se asume que el -1 no se utiliza nunca en el array
    int dato = -1;

    if(pos < util &&  pos >= 0)
        dato = info[pos];
    
    return dato;
    // NORMA DE DISEÑO: 
    // Intentar no poner nunca varios return statements en una misma función
}

void VectorSD::aniadir(int dato)
{
    if(reservado == util) {
        // Reservamos un nuevo array
        int *newInfo = new int[2*reservado];

        // Copia de los elementos al nuevo array
        for(int i = 0; i < util; i++) {
            newInfo[i] = info[i];
        }

        // Liberamos la memoria del antiguo array
        delete [] info;

        // Actualizamos el objeto
        reservado*=2;
        info = newInfo;
    }

    info[util] = dato;
    util++;
}

void VectorSD::copia(const VectorSD &vector)
{
    liberar();

    info = new int[vector.reservado];
    for(int i = 0; i < vector.util; i++) {
        info[i] = vector.info[i];
    }
    
    reservado = vector.reservado;
    util = vector.util;
}

void VectorSD::liberar()
{
    if(info){
        delete [] info;
        info = 0;
    }
    util = 0;
    reservado = 0;
}

void VectorSD::mostrar(ostream &flujo) const
{
    for (int i = 0; i < util; i++) {
        flujo << info[i] << " ";
    }
    flujo << endl;
}

void VectorSD::leer(istream &flujo)
{
    int dato;
    while (flujo >> dato) {
        aniadir(dato);
    }
}