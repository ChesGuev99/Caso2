 #include<iostream>

 using namespace std;


 class Media{
     public:
        virtual void execute(){

        }
 };


 class Television: public Media{
     public:
        void execute(){
            cout<<"Se enciende la television"<<endl;
        }

 };

 class Radio: public Media{
     void execute(){
         cout<<"Se enciende la radio"<<endl;
     }
 };

class Music : public Media{

};

class Spotify : public Music{

};

class Youtube : public Music{

};