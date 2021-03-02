#include<iostream>
#include <vector>

using namespace std;

// Esta clase funciona como observer, esta encargado de avisar al usuario que
// Media se está utilizando actualmente
class Emision {
public:
    // La función actual puede recibir uno o 2 char* , y con estos avisa al usuario que Media se
    // está emitiendo y en que aplicación de ser el segundo caso.
    void actual(string medio) {
        cout<<"Actualmente se esta emitiendo "<< medio<<endl;
    }

    void actual(string medio, string app) {
        cout<<"Actualmente se está emitiendo " <<medio<<" en "<<app<<endl;
    }
};

/*
Clase abstracta por el metodo execute
Hereda a Television,Radio y Music
*/
class Media {
    // emisor es el observer de la clase Media
    // status indica cual se esta emitiendo, 0 = off y 1 = On
protected:
    Emision emisor;
    bool status;
public:
    virtual void execute() {

    }

    // update llama al emisor para avisar que hubo un cambio
    void update(string media) {
        emisor.actual(media);
    }

    void setStatus(bool status) {
        status = status;
        if (status == 1) {
            execute();
        }
    }
};

/*
Clase derivada de Media
Define el metodo execute de manera distinta
*/
class Television : public Media {
public:
    void execute() {
        cout << "Se enciende la television" << endl;
        this->update("Television");
    }

};

/*
Clase derivada de Media
Define el metodo execute de manera distinta
*/
class Radio : public Media {
    void execute() {
        cout << "Se enciende la radio" << endl;
        this->update("Radio");

    }
};


/*
Clase derivada de Media
Define el metodo execute de manera distinta
Hereda a Spotify y a Music
*/
class Music : public Media {
private:

public:
    void update_Music(string media, string app) {
        emisor.actual(media, app);
    }

    // excecute es ejecutada según la subclase, ya sea Spotify o Youtube
    void execute(){
        cout<<"hola";
    }
};

class Spotify : public Music{
    void execute() {
        cout << "Se escucha Spotify" << endl;
        this->update_Music("Musica", "Spotify");
    }

};

class Youtube : public Music{
    void execute() {
        cout << "Se escucha Youtube" << endl;
        this->update_Music("Musica", "Youtube");
    }
};

// La clase App es la encargada de modificar todos los elementos agregados y
// que estos a su vez notifiquen al observer
class App {
private:
    vector<Media *> Emisores;

public:
    // attach es la función encargada de agregar un elemento de clase Media a la lista de Emisores
    void attach(Media *emisor) {
        Emisores.push_back(emisor);
    }

    // execute emisor se encarga de modificar el status de todos los elementos a 0(Off)
    // y aquel que debe estar activado en 1 (On)
    void executeEmisor(Media *actual) {
        for (Media *emisor: Emisores) {
            if (emisor != actual) {
                emisor->setStatus(0);
            } else {
                emisor->setStatus(1);
            }
        }
    };
};