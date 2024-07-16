#include <iostream>
#include <stdlib.h>
#include <stdexcept>

using namespace std;

bool motorProblem(){
    srand(time(NULL));
    return rand()%2==0;
}

class Motor{
private:
    bool problem;
public:
    Motor(bool p=false){
        problem=p;
        if(problem==true){
            throw runtime_error("Problem so motorot.");
        }
    }
};

class Avtomobil{
public:
    Motor motor;

    Avtomobil(bool p=false) try: motor(motorProblem()){

    }catch (const runtime_error& e){
        cout<<"Faten isklucok vo klasa Avtomobil: "<<e.what()<<endl;
        throw;
    }
};

class Garaza {
public:
    Avtomobil avtomobil;

    Garaza() try : avtomobil(){

    }catch (const runtime_error& e){
        cout<<"Faten isklucok vo klasa Garaza: "<<e.what()<<endl;
        throw runtime_error("Problem za inicijalizacija na objekt od tip Garaza, poradi problem so motorot na avtomobilot.");
    }
};


int main()
{
    try{
        Garaza G;
    }catch (const runtime_error& e){
        cout << "Faten isklucok vo main: "<<e.what()<<endl;
    }
    return 0;
}
