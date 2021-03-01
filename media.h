#include<iostream>
#include <vector>

using namespace std;

// Esta clase funciona como observer, esta encargado de avisar al usuario que
// Media se está utilizando actualmente
class Emision {
public:
    // La función actual puede recibir uno o 2 char* , y con estos avisa al usuario que Media se
    // está emitiendo y en que aplicación de ser el segundo caso.
    void actual(char *medio) {
        printf("Actualmente se está emitiendo %s", medio);
    }

    void actual(char *medio, char *app) {
        printf("Actualmente se está emitiendo %s en %s", medio, app);
    }
};

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
    void update(char *media) {
        emisor.actual(media);
    }

    void setStatus(bool status) {
        status = status;
        if (status == 1) {
            execute();
        }
    }
};


class Television : public Media {
public:
    void execute() {
        cout << "Se enciende la television" << endl;
        this->update("Television");
    }

};

class Radio : public Media {
    void execute() {
        cout << "Se enciende la radio" << endl;
        this->update("Radio");

    }
};

class Music : public Media {
private:

public:
    void update(char *media, char *app) {
        emisor.actual(media, app);
    }

    // excecute es ejecutada según la subclase, ya sea Spotify o Youtube
    virtual void execute() {
    }

};

class Spotify : public Music {
    void execute() {
        cout << "Se escucha Spotify" << endl;
        this->update("Musica", "Spotify");
    }

};

class Youtube : public Music {
    void execute() {
        cout << "Se escucha Youtube" << endl;
        this->update("Musica", "Youtube");
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

