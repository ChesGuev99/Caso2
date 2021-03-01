#ifndef _Pila_
#define _Pila_
#include "Lista.h"

template <class T>
class Pila : public Lista<T>
{
public:
    
    Pila() { Lista<T>::primero = NULL; }
    void push(T v){Lista<T>::insertarInicio(v);}
    T pop(){
        T aux= Lista<T>::primero->valor;
        Nodo<T>* nAux= Lista<T>::primero;
        Lista<T>::primero=Lista<T>::primero->siguiente;
        delete nAux;
        return aux;
    }
};

#endif