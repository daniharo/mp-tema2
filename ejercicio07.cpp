#include <iostream>
#include <string.h>
using namespace std;

const int TAM = 20;

int compararCadenas(const char cad1[], const char cad2[])
{
    int long1, long2;
    for(long1 = 0; *(cad1 + long1) != '\0'; long1++);
    for(long2 = 0; *(cad2 + long2) != '\0'; long2++);

    return (long1 - long2);
}

bool insertaCadena(const char *aInsertar, char *cad, const int posInser)
{
    bool res = false;
    int longAInsertar = strlen(aInsertar);
    int longOriginal = strlen(cad);

    if(longAInsertar + longOriginal < TAM) {
        // Se copian los datos que ocupan las posiciones de inserción
        for(int i = longOriginal + longAInsertar - 1; i >= posInser + longAInsertar; i--) {
            cad[i] = *(cad+i-longAInsertar);
        }

        // Se realiza la inserción
        for(int i=posInser, j=0; j < longAInsertar; i++, j++) {
            *(cad + i) = *(aInsertar + j);
        }

        res = true;

        *(cad+longOriginal+longAInsertar) = '\0';
    }

    return res;
}

int main()
{
    return 0;
}