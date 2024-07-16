#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main()
{
    string zbor;

    ofstream outdat("datoteka.dat",ios::out);
    if(!outdat){
        cout<<"Datotekata ne moze da se otvori"<<endl;
        exit(1);
    }

    cout<<"Vnesi tekst vo datotekata(CTRL+Z za kraj):"<<endl;
    while(cin>>zbor){
        outdat<<zbor<<" ";
    }
    outdat.close();

    ifstream indat("datoteka.dat",ios::in);
    if(!indat){
        cout<<"Datotekata ne moze da se otvori"<<endl;
        exit(1);
    }
    ofstream outnova("nova.dat",ios::out);
    if(!outnova){
        cout<<"Datotekata ne moze da se otvori"<<endl;
        exit(1);
    }

    while(indat>>zbor){
        if(zbor.length()<10)
            outnova<<zbor<<" ";
    }
    indat.close();
    outnova.close();

    ifstream innova("nova.dat",ios::in);
    if(!innova){
        cout<<"Datotekata ne moze da se otvori"<<endl;
        exit(1);

    }

    cout<<"Datoteka nova.dat:"<<endl;
    while(innova>>zbor){
        cout<<zbor<<", ";
    }
    innova.close();

    return 0;
}
