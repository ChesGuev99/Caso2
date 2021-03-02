#include "Cola.h"
#include "Pila.h"
#include "media.h"
#include <string>
using namespace std;


int main()
{
    
    /*Cola<int>* prueba =new Cola<int>();
    prueba->push(1234);
    prueba->push(5678);
    prueba->push(9012);
    prueba->mostrar();
    cout << "popped: " << prueba->pop() << endl;
    prueba->mostrar();
    prueba->pop();
    prueba->mostrar();
    prueba->pop();

    prueba->mostrar();
    */
    cout << "Donezo" << endl;
    cin.get();
    
    
    int opcionMenu;
    App programa; 
//Creacion de cada medio
    Media* television = new Television;
    Media* radio = new Radio;
    Media* spotify = new Spotify;
    Media* youtube = new Youtube;

//Se ingresan al vector de la app
    programa.attach(television);
    programa.attach(radio);
    programa.attach(spotify);
    programa.attach(youtube);
    
    Media* eleccion;
    while(true){
        
        cout<<"Menu de opciones, Que desea hacer?"<<endl;
        cout<<"1. Ver television"<<endl;
        cout<<"2. Escuchar radio"<<endl;
        cout<<"3. Escuchar en Spotify"<<endl;
        cout<<"4. Escuchar en YouTube"<<endl;
        cout<<"5. Salir"<<endl;
        cin>>opcionMenu;

        switch (opcionMenu)
        {
        case 1:
            eleccion = television;
            break;
        case 2:
            eleccion = radio;
            break;
        case 3:
            eleccion = spotify;
            break;
        case 4:
            eleccion = youtube;
            break;
        case 5:
            return 0;
        default:
            cout<<"No existe este codigo, ingrese uno valido"<<endl;
            break;
        }
        programa.executeEmisor(eleccion);
        
    }

}