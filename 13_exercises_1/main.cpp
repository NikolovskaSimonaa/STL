#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <fstream>

using namespace std;

class Pravoagolnik{
private:
    double sirina;
    double dolzina;
public:
    Pravoagolnik(double s, double d){
        sirina=s;
        dolzina=d;
    }
    double Perimetar(){
        return sirina+dolzina;
    }
    void print(){
        cout<<"Pravoagolnik: a="<<dolzina<<" b="<<sirina<<endl;
    }
    friend double operator+(double sum, Pravoagolnik &P){
        sum+=P.Perimetar();
        return sum;
    }
};

class Kvadrat{
private:
    double strana;
public:
    Kvadrat(double s){
        strana=s;
    }
    double Perimetar(){
        return strana;
    }
    void print(){
        cout<<"Kvadrat: a="<<strana<<endl;
    }
    friend double operator+(double sum, Kvadrat &K){
        sum+=K.Perimetar();
        return sum;
    }
};

int main()
{
    double dolzina, sirina, strana;
    int id;

    ofstream outdat1("datoteka1.dat",ios::out);
    if(!outdat1){
        cout<<"Datotekata ne moze da se otvori"<<endl;
        exit(1);
    }
    ofstream outdat2("datoteka2.dat",ios::out);
    if(!outdat2){
        cout<<"Datotekata ne moze da se otvori"<<endl;
        exit(1);
    }

    cout<<" Datoteka 1: Vnesi identifikator(1 - pravoagolnik, 2 - kvadrat)"<<endl;
    cin>>id;
    while(id==1 || id==2){
        if(id==1){
            cout<<"Vnesi dolzina i sirina za pravoagolnik:"<<endl;
            cin>>dolzina>>sirina;
            outdat1<<id<<" "<<dolzina<<" "<<sirina<<endl;
        }else{ //if id==2
            cout<<"Vnesi strana za kvadrat:"<<endl;
            cin>>strana;
            outdat1<<id<<" "<<strana<<endl;
        }
        cout<<"Vnesi identifikator(1 - pravoagolnik, 2 - kvadrat)"<<endl;
        cin>>id;
    }
    outdat1.close();

    cout<<" Datoteka 2: Vnesi identifikator(1 - pravoagolnik, 2 - kvadrat)"<<endl;
    cin>>id;
    while(id==1 || id==2){
        if(id==1){
            cout<<"Vnesi dolzina i sirina za pravoagolnik:"<<endl;
            cin>>dolzina>>sirina;
            outdat2<<id<<" "<<dolzina<<" "<<sirina<<endl;
        }else{ //if id==2
            cout<<"Vnesi strana za kvadrat:"<<endl;
            cin>>strana;
            outdat2<<id<<" "<<strana<<endl;
        }
        cout<<"Vnesi identifikator(1 - pravoagolnik, 2 - kvadrat)"<<endl;
        cin>>id;
    }
    outdat2.close();

    ifstream indat1("datoteka1.dat",ios::in);
    if(!indat1){
        cout<<"Datotekata ne moze da se otvori"<<endl;
        exit(1);
    }
    ifstream indat2("datoteka2.dat",ios::in);
    if(!indat2){
        cout<<"Datotekata ne moze da se otvori"<<endl;
        exit(1);
    }

    vector<Pravoagolnik> V1;
    vector<Kvadrat> V2;
    while(indat1>>id){
        try{
            if(id==1){
                indat1>>dolzina>>sirina;
                V1.push_back(Pravoagolnik(sirina, dolzina));
            }else if(id==2){
                indat1>>strana;
                V2.push_back(Kvadrat(strana));
            }else
                throw false;
        }catch(bool){
            cout<<"Vo datotekata se najdeni nesoodvetni podatoci, koi ne moze da bidat procitani soodvetno"<<endl;
            exit(1);
        }
    }
    while(indat2>>id){
        try{
            if(id==1){
                indat2>>dolzina>>sirina;
                V1.push_back(Pravoagolnik(sirina, dolzina));
            }else if(id==2){
                indat2>>strana;
                V2.push_back(Kvadrat(strana));
            }else
                throw false;
        }catch(bool){
            cout<<"Vo datotekata se najdeni nesoodvetni podatoci, koi ne moze da bidat procitani soodvetno"<<endl;
            exit(1);
        }
    }
    indat1.close();
    indat2.close();

    double unijaP, presekP, unijaK, presekK;
    unijaP=accumulate(V1.begin(),V1.end(),0.0); // go presmetuva vkupniot perimetar na pravoagolnicite
    presekP=unijaP/V1.size();
    unijaK=accumulate(V2.begin(),V2.end(),0.0); // go presmetuva vkupniot perimetar na kvadratite
    presekK=unijaK/V2.size();
    cout<<"Unija na site pravoagolnici: "<<unijaP<<endl;
    cout<<"Presek na site pravoagolnici: "<<presekP<<endl;
    cout<<"Unija na site kvadrati: "<<unijaK<<endl;
    cout<<"Presek na site kvadrati: "<<presekK<<endl;

    return 0;
}
