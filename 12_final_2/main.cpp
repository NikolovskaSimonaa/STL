#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <numeric>

using namespace std;

class Inventar{
private:
    int id;
    int kolicestvo;
    double cena;
public:
    Inventar(int ID=0, int k=0, double c=0.0){
        id=ID;
        kolicestvo=k;
        cena=c;
    }
    int getKolicestvo()const{
        return kolicestvo;
    }
    friend double operator+(double sum, Inventar &I){
        sum+=I.cena*I.kolicestvo;
        return sum;
    }
    void print()const{
        cout<<"ID: " <<id<<endl;
        cout<<"Kolicestvo: "<<kolicestvo<<endl;
        cout<<"Cena: "<<cena<<endl;
    }

};


int main()
{
    ofstream outdat("inventar.dat",ios::out);
    try{
        if(!outdat)
            throw true;
    }catch(bool){
        cout<<"Datotekata ne moze da se otvori"<<endl;
        exit(1);
    }
    int id, kolicestvo;
    double cena;
    cout<<"Vnesi id, kolicestvo i cena za artiklite(CTRL+Z za kraj):"<<endl;
    while(cin>>id>>kolicestvo>>cena){
        outdat<<id<<" "<<kolicestvo<<" "<<cena<<endl;
    }
    outdat.close();

    vector<Inventar> V;
    ifstream indat("inventar.dat",ios::in);
    try{
        if(!indat)
            throw true;
    }catch(bool){
        cout<<"Datotekata ne moze da se otvori"<<endl;
        exit(1);
    }
    while(indat>>id>>kolicestvo>>cena){
        V.push_back(Inventar(id, kolicestvo, cena));
    }
    indat.close();

    double sum=accumulate(V.begin(),V.end(),0.0);
    cout<<"Vkupna vrednost na artiklite: "<<sum<<endl;
    vector<Inventar>::const_iterator iterator=V.begin();
    cout<<"Lista na artkli za koi kolicestvoto e pomalo od 10:"<<endl;
    while(iterator!=V.end()){
        if(iterator->getKolicestvo()<10){
            iterator->print();
            cout<<endl;
        }
        iterator++;
    }

    return 0;
}
