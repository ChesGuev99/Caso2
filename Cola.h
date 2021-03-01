#ifndef _Cola_
#define _Cola_
#include "Lista.h"

template <class T>
class Cola : public Lista<T>
{
public:
    Cola() {Lista<T>::primero = NULL;}
    void push(T v){Lista<T>::insertarFinal(v);}
    T pop(){
        T aux=Lista<T>::primero->valor;
        Nodo<T>* nAux=Lista<T>::primero;
        Lista<T>::primero=Lista<T>::primero->siguiente;
        delete nAux;
        return aux;

    }
};

#endif