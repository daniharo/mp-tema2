/* 
 * File:   main.cpp
 * Author: mgomez
 *
 * Created on 14 de abril de 2013, 18:28
 */
#include <iostream>
#include "Matriz2D.h"

using namespace std;

/*
 * 
 */
int main() {

    // PRUEBA EJERCICIO 17 (Matria2D_1)

    cout << "***************** PRUEBA EJERCICIO 17 (Matriz2D_1) *****************" << endl << endl;
    // Se crea un objeto de la clase Matriz2D_1 con 5 filas y 5 columnas
    Matriz2D_1<int> obj1(5, 5);

    // Se asignan los valores
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            obj1.modificar(i - 1, j - 1, i * j);
        }
    }
    
    // la matriz asignada es:
    // 1   2   3   4   5
    // 2   4   6   8  10
    // 3   6   9  12  15
    // 4   8  12  16  20
    // 5  10  15  20  25
    
    // Se muestra el contenido
    cout << "Matriz original: " << endl;
    obj1.mostrar();
    
    // se obtiene el numero de filas y columna
    cout << "Numero filas (debe ser 5): " << obj1.getnFilas() 
            << " numero de columnas (debe ser 5): " << obj1.getnColumnas() << endl;
    
    // se obtiene el valor que esta en la posicion (2,2)
    cout << "Elemento (2, 2) (debe ser 9): " <<obj1.obtenerValor(2, 2) << endl;

    // Se realiza la copia de obj1 sobre obj2
    Matriz2D_1<int> obj2(1,1);
    obj2.copia(obj1);

    // Se muestra la matriz creada mediante copia
    cout << endl << endl << "Matriz copiada a partir de la original: " << endl;
    obj2.mostrar();

    // Se libera obj2
    obj2.liberar();

    // se extrae una submatriz y se recoge sobre un puntero
    cout << endl << endl << "Submatriz desde elemento (2,1) hasta (4,3)" << endl;
    Matriz2D_1<int> *obj3 = obj1.submatriz(2, 1, 4, 3);

    // Se muestra por pantalla la matriz extraida y se libera
    // su espacio
    if (obj3 != 0) {
        obj3->mostrar();
        delete obj3;
    }

    // Se elimina de copia de obj1 la primera fila
    Matriz2D_1<int> obj4(1,1);
    obj4.copia(obj1);
    obj4.eliminaFila(0);

    // Se muestra por pantalla el objeto obtenido
    cout << "Matriz obtenida al eliminar la primera fila: " << endl;
    obj4.mostrar();
    
    // Se libera espacio de obj4
    obj4.liberar();
    
    // Se elimina ed copia de obj1 la ultima de las filas
    Matriz2D_1<int> obj5(1,1);
    obj5.copia(obj1);
    obj5.eliminaFila(4);
    
    // Se muestra por pantalla el objeto obtenido
    cout << "Matriz obtenida al eliminar la ultima fila: " << endl;
    obj5.mostrar();
    
    // Se libera espacio de obj5
    obj5.liberar();
    
    // se elimina de copia de objeto1 una fila intermedia
    Matriz2D_1<int> obj6(1,1);
    obj6.copia(obj1);
    obj6.eliminaFila(2);
    
    // Se muestra por pantalla el objeto obtenido
    cout << "Matriz obtenida al eliminar fila intermedia:" << endl;
    obj6.mostrar();
    
    // Se libera espacio de obj6
    obj6.liberar();

    // Se elimina de copia de obj1 la primera columna
    Matriz2D_1<int> obj7(1,1);
    obj7.copia(obj1);
    obj7.eliminaColumna(0);
    
    // Se muestra por pantalla el objeto obtenido
    cout << "Matriz obtenida al eliminar la columna 0 sobre la anterior: " << endl;
    obj7.mostrar();
    
    // Se libera espacio de obj7
    obj7.liberar();
    
    // Se elimina de copia de obj1 la ultima columna
    Matriz2D_1<int> obj8(1,1);
    obj8.copia(obj1);
    obj8.eliminaColumna(4);
    
    // Se muestra por pantalla el objeto obtenido
    cout << "Matriz obtenida al eliminar la ultima columna sobre la anterior: " << endl;
    obj8.mostrar();
    
    // Se libera espacio de obj8
    obj8.liberar();
    
    // Se elimina de copia de obj1 una columna intermedia
    Matriz2D_1<int> obj9(1,1);
    obj9.copia(obj1);
    obj9.eliminaColumna(2);
    
    // Se muestra por pantalla el objeto obtenido
    cout << "Matriz obtenida al eliminar la columna 2 sobre la anterior: " << endl;
    obj9.mostrar();
    
    // Se libera espacio de obj9
    obj9.liberar();

    // Se copia obj1 como Matriz2D_2
    Matriz2D_2<int> obj10 = obj1.toMatriz2D_2();
    cout << "Matriz representada como Matriz2D_2: " << endl;
    obj10.mostrar();

    // Se libera el espacio de obj10
    obj10.liberar();

    // Se libera el espacio de obj1
    obj1.liberar();

    /******************************************************************************************/
    /******************************************************************************************/
    // PRUEBA EJERCICIO 18 (Matria2D_2)

    cout << endl << endl << endl;
    cout << "********************************************************************" << endl;
    cout << "***************** PRUEBA EJERCICIO 18 (Matriz2D_2) *****************" << endl << endl;
    // Se crea un objeto de la clase Matriz2D_2 con 5 filas y 5 columnas
    Matriz2D_2<int> obj_1(5, 5);

    // Se asignan los valores
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            obj_1.modificar(i - 1, j - 1, i * j);
        }
    }
    
    // la matriz asignada es:
    // 1   2   3   4   5
    // 2   4   6   8  10
    // 3   6   9  12  15
    // 4   8  12  16  20
    // 5  10  15  20  25
    
    // Se muestra el contenido
    cout << "Matriz original: " << endl;
    obj_1.mostrar();
    
    // se obtiene el numero de filas y columna
    cout << "Numero filas (debe ser 5): " << obj_1.getnFilas() 
            << " numero de columnas (debe ser 5): " << obj_1.getnColumnas() << endl;
    
    // se obtiene el valor que esta en la posicion (2,2)
    cout << "Elemento (2, 2) (debe ser 9): " <<obj_1.obtenerValor(2, 2) << endl;

    // Se realiza la copia de obj_1 sobre obj_2
    Matriz2D_2<int> obj_2(1,1);
    obj_2.copia(obj_1);

    // Se muestra la matriz creada mediante copia
    cout << endl << endl << "Matriz copiada a partir de la original: " << endl;
    obj_2.mostrar();

    // Se libera obj_2
    obj_2.liberar();

    // se extrae una submatriz y se recoge sobre un puntero
    cout << endl << endl << "Submatriz desde elemento (2,1) hasta (4,3)" << endl;
    Matriz2D_2<int> *obj_3 = obj_1.submatriz(2, 1, 4, 3);

    // Se muestra por pantalla la matriz extraida y se libera
    // su espacio
    if (obj_3 != 0) {
        obj_3->mostrar();
        delete obj_3;
    }

    // Se elimina de copia de obj_1 la primera fila
    Matriz2D_2<int> obj_4(1,1);
    obj_4.copia(obj_1);
    obj_4.eliminaFila(0);

    // Se muestra por pantalla el objeto obtenido
    cout << "Matriz obtenida al eliminar la primera fila: " << endl;
    obj_4.mostrar();
    
    // Se libera espacio de obj_4
    obj_4.liberar();
    
    // Se elimina ed copia de obj_1 la ultima de las filas
    Matriz2D_2<int> obj_5(1,1);
    obj_5.copia(obj_1);
    obj_5.eliminaFila(4);
    
    // Se muestra por pantalla el objeto obtenido
    cout << "Matriz obtenida al eliminar la ultima fila: " << endl;
    obj_5.mostrar();
    
    // Se libera espacio de obj_5
    obj_5.liberar();
    
    // se elimina de copia de objeto1 una fila intermedia
    Matriz2D_2<int> obj_6(1,1);
    obj_6.copia(obj_1);
    obj_6.eliminaFila(2);
    
    // Se muestra por pantalla el objeto obtenido
    cout << "Matriz obtenida al eliminar fila intermedia:" << endl;
    obj_6.mostrar();
    
    // Se libera espacio de obj_6
    obj_6.liberar();

    // Se elimina de copia de obj_1 la primera columna
    Matriz2D_2<int> obj_7(1,1);
    obj_7.copia(obj_1);
    obj_7.eliminaColumna(0);
    
    // Se muestra por pantalla el objeto obtenido
    cout << "Matriz obtenida al eliminar la columna 0 sobre la anterior: " << endl;
    obj_7.mostrar();
    
    // Se libera espacio de obj_7
    obj_7.liberar();
    
    // Se elimina de copia de obj_1 la ultima columna
    Matriz2D_2<int> obj_8(1,1);
    obj_8.copia(obj_1);
    obj_8.eliminaColumna(4);
    
    // Se muestra por pantalla el objeto obtenido
    cout << "Matriz obtenida al eliminar la ultima columna sobre la anterior: " << endl;
    obj_8.mostrar();
    
    // Se libera espacio de obj_8
    obj_8.liberar();
    
    // Se elimina de copia de obj_1 una columna intermedia
    Matriz2D_2<int> obj_9(1,1);
    obj_9.copia(obj_1);
    obj_9.eliminaColumna(2);
    
    // Se muestra por pantalla el objeto obtenido
    cout << "Matriz obtenida al eliminar la columna 2 sobre la anterior: " << endl;
    obj_9.mostrar();
    
    // Se libera espacio de obj_9
    obj_9.liberar();

    // Se copia obj_1 como Matriz2D_1
    Matriz2D_1<int> obj_10 = obj_1.toMatriz2D_1();
    cout << "Matriz representada como Matriz2D_1: " << endl;
    obj_10.mostrar();

    // Se libera el espacio de obj10
    obj_10.liberar();
    
    // se libera el espacio de obj_1
    obj_1.liberar();
}
