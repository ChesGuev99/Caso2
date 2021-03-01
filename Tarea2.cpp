#include "Cola.h"
#include "Pila.h"
#include "media.h"
#include <string>
using namespace std;


int main()
{
    /*
    Cola<int>* prueba =new Cola<int>();
    prueba->push(1234);
    prueba->push(5678);
    prueba->push(9012);
    prueba->mostrar();
    cout << "popped: " << prueba->pop() << endl;
    prueba->mostrar();
    prueba->pop();
    prueba->mostrar();
    prueba->pop();
    prueba->pop();
    prueba->pop();
    prueba->mostrar();
    cout << "Donezo" << endl;
    cin.get();
    */
    bool continuarCiclo = true;
    int opcionMenu;
    Media* accion;
    while(continuarCiclo){
        
        cout<<"Menu de opciones, Que desea hacer?"<<endl;
        cout<<"1. Ver television"<<endl;
        cout<<"2. Escuchar radio"<<endl;
        cout<<"3. Escuchar musica"<<endl;
        cout<<"4. Salir"<<endl;
        cin>>opcionMenu;

        switch (opcionMenu)
        {
        case 1:
            accion = new Television;
            break;
        case 2:
            accion = new Radio;
            break;
        case 3:
            accion = new Music;
            break;
        case 4:
            continuarCiclo = !continuarCiclo;
            break;
        default:
            cout<<"No existe este codigo, ingrese uno valido"<<endl;
            break;
        }
        accion->execute();
    }



    return 0;
}