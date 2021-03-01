#ifndef _Lista_
#define _Lista_
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cctype>
#include "Nodo.h"

template <class T>
class Lista
{
    
public:
    Nodo<T>* primero;

    Lista() { primero = NULL; }
    //retorna true si está vacía y false si tiene al menos sun elemento
    bool listaVacia() { return primero == NULL; }

    ~Lista()
    {
        Nodo<T>* aux;

        while (primero)
        {
            aux = primero;
            primero = primero->siguiente;
            delete aux;
        }
    }
//retorna el largo de la lista
    int largoLista()
    {
        int cont = 0;

        Nodo<T>* aux;
        aux = primero;
        if (listaVacia())
        {
            return cont;
        }
        else
        {
            while (aux != NULL)
            {
                aux = aux->siguiente;
                cont++;
            }
            return cont;
        }
    }
//Crea un nodo con el valor pasado por parámetro y lo agrega al final
    void insertarFinal(T v)
    {
        if (listaVacia()){
            primero = new Nodo<T>(v);
        }
        else
        {
            Nodo<T>* aux = primero;
            while (aux->siguiente != NULL)
                aux = aux->siguiente;
            aux->siguiente = new Nodo<T>(v);
        }
    }
//Crea un nodo con el valor pasado por parámetro y lo agrega al inicio
    void insertarInicio(T v)
    {
        if (listaVacia()){
            primero = new Nodo<T>(v);
        }
        else
        {
            Nodo<T>* aux = new Nodo<T>(v);
            aux->siguiente=primero;
            primero = aux;
        }
    }

//Hace un cout del contenido de los nodos
    void mostrar()
    {
        std::cout << "Lista: ";
        Nodo<T>* aux;
        if (primero == NULL)
            std::cout << "No hay elementos" << std::endl;
        else
        {

            aux = primero;
            while (aux)
            {
                std::cout << aux->valor << "-> ";
                aux = aux->siguiente;
            }
            std::cout << std::endl;
        }
    }
    
    
};

#endif