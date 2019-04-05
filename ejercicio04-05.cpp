#include "utilarray.h"
#include <iostream>
using namespace std;

int main()
{
    int CAP = 50;
    int array[CAP];
    int util = leerArray(array, CAP);

    int arrayCopia[CAP];
    for(int i = 0; i < util; i++)
        arrayCopia[i] = array[i];
    
    // Primer recorrido

    for(int i = 0; i < util; i++)
        if(array[i] < 0)
            array[i] = -array[i];
    
    // Segundo recorrido

    int *ptr = &arrayCopia[util];

    while(ptr > arrayCopia) {
        ptr--;
        
        if(*ptr < 0)
            *ptr = -(*ptr);
    }
    
    imprimirArray(array, util);
    imprimirArray(arrayCopia, util);

    return 0;
}