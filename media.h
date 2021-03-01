#include<iostream>
#include <vector>

using namespace std;

class Emision{
public:
    void actual(char *medio){
        printf("Actualmente se está emitiendo %s", medio);
    }
    void actual(char *medio, char *app){
        printf("Actualmente se está emitiendo %s en %s", medio, app);
    }
};

 class Media{
 protected:
        Emision emisor;
        bool status;
     public:
        virtual void execute(){

        }
        void update(char *media){
            emisor.actual(media);
        }

         void setStatus(bool status) {
             status = status;
             if(status == 1){
                 execute();
             }
         }
 };


 class Television: public Media{
     public:
        void execute(){
            cout<<"Se enciende la television"<<endl;
            this->update("Television");
        }

 };

 class Radio: public Media{
     void execute(){
         cout<<"Se enciende la radio"<<endl;
         this->update("Radio");

     }
 };

class Music : public Media{
private:

public:
    void update(char *media, char *app){
        emisor.actual(media, app);
    }
    virtual void execute() {
    }

};

class Spotify : public Music{
    void execute() {
        cout << "Se escucha Spotify" << endl;
        this->update("Musica","Spotify");
    }

};

class Youtube : public Music{
    void execute() {
        cout << "Se escucha Youtube" << endl;
        this->update("Musica","Youtube");
    }
};


class App{
private:
    vector<Media*> Emisores;

public:
    void attach(Media *emisor){
        Emisores.push_back(emisor);
    }

    void executeEmisor(Media *actual){
        for(Media *emisor: Emisores){
            if(emisor != actual){
                emisor->setStatus(0);
            }
            else{
                cout << "founddd";
                emisor->setStatus(1);
            }
        }
    };
};

