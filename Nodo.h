#ifndef _Nodo_
#define _Nodo_


template <class T>
class Nodo
{
public:
	Nodo(T dato)
    {
        valor=dato;
        siguiente=NULL;
    }
	T valor;
    Nodo<T>* siguiente;

	friend class lista;
};

#endif