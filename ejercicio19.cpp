#include <iostream>
using namespace std;

struct Celda{
    double info;
    Celda *sig;
};

class Lista
{
    Celda *l;

public:

    /**
     * @brief Construye un objeto de tipo Lista como lista vacía
     * 
     */
    Lista(void): l(0) {}

    /**
     * @brief Añade al final de la secuencia de celdas enlazadas un nuevo dato
     * 
     * @param dato 
     */
    void aniadir(double dato)
    {
        Celda *nuevoDato = new Celda;
        nuevoDato->info = dato;
        nuevoDato->sig = 0;

        if(!l) {
            l = nuevoDato;
        }
        else{
            Celda *cursor = l;
            while(cursor->sig)
                cursor = cursor->sig;
            cursor->sig = nuevoDato;
        }
    }

    /**
     * @brief Elimina la última celda del objeto
     * 
     */
    void eliminaUltimaCelda(void)
    {
        if(l) {
            if(!(l->sig)){
                delete l;
                l = 0;
            }
            else{
                Celda *cursor = l;
                while(cursor->sig->sig)
                    cursor = cursor->sig;
                
                delete cursor->sig;
                cursor->sig = 0;
            }
        }
    }

    /**
     * @brief Elimina y libera toda la información contenida en el objeto
     * 
     */
    void eliminarTodo(void)
    {
        while(l)
            eliminaUltimaCelda();
    }

    /**
     * @brief Muestra en la salida estándar el contenido completo del objeto
     * 
     */
    void mostrar(void)
    {
        Celda *cursor = l;
        while(cursor) {
            cout << cursor->info << " ";
            cursor = cursor->sig;
        }
    }

    /**
     * @brief Inserta un nuevo dato detrás de una celda concreta
     * 
     * @param nuevoDato nuevo dato
     * @param dir dirección de memoria de la celda anterior a la inserción
     */
    void insertaDato(double nuevoDato, Celda *dir)
    {
        if(!dir) {
            Celda *nuevaCelda = new Celda;
            nuevaCelda->sig = l;
            nuevaCelda->info = nuevoDato;
            l = nuevaCelda;
        }
        else{
            Celda *tmp = dir->sig;
            dir->sig = new Celda;
            dir->sig->info = nuevoDato;
            dir->sig->sig = tmp;
        }
    }

    /**
     * @brief Elimina una celda
     * 
     * @param dir dirección de memoria de la celda
     */
    void eliminaDir(Celda* dir)
    {
        Celda *tmp = dir->sig;
        dir->sig = tmp->sig;
        dir->info = tmp->info;
        delete tmp;
    }

    /**
     * @brief Devuelve un puntero a la celda que se encuentra en una
     * determinada posición de la lista.
     * 
     * @param pos Posición
     * @return Celda* Dirección de memoria de la celda
     */
    Celda* posicion(int pos)
    {
        Celda *cursor = l;
        for(int i = 0; i < pos; i++)
            cursor = cursor->sig;
        
        return cursor;
    }
};