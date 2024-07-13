#include <iostream>

using namespace std;

class Kvadrat{
private:
    int a;
public:
    Kvadrat(int x=1){
        a=x;
    }
    Kvadrat(Kvadrat &K){
        a=K.a;
    }
    void print(){
        cout<<"Kvadrat: a="<<a<<endl;
    }
    int getPlostina(){
        return a*a;
    }
    Kvadrat operator=(Kvadrat &K){
        a=K.a;
        return *this;
    }
};

class Pravoagolnik{
private:
    int a, b;
public:
    Pravoagolnik(int x=1, int y=1){
        a=x;
        b=y;
    }
    Pravoagolnik(Pravoagolnik &P){
        a=P.a;
        b=P.b;
    }
    void print(){
        cout<<"Pravoagolnik: a="<<a <<" b="<<b<<endl;
    }
    int getPlostina(){
        return a*b;
    }
    Pravoagolnik operator=(Pravoagolnik &P){
        a=P.a;
        b=P.b;
        return *this;
    }
};

class Krug{
private:
    int radius;
public:
    Krug(int r=1){
        radius=r;
    }
    Krug(Krug &K){
        radius=K.radius;
    }
    void print(){
        cout<<"Krug: r="<<radius<<endl;
    }
    float getPlostina(){
        return radius*radius*3.14;
    }
    Krug operator=(Krug &K){
        radius=K.radius;
        return *this;
    }
};

template<class T>
class Mnozestvo{
private:
    T *niza;
    int dolzina;
    int br; //brojac za iteriranje niz nizata
public:
    Mnozestvo(int s=1){
        dolzina=s;
        br=0;
        niza=new T[s];
    }
    void dodadiElement(T e){
        niza[br]=e;
        br++;
    }
    void prikaziElement(int i){
        niza[i].print();
    }
    T maxElement(){
        T max=niza[0];
        float m, n;
        for(int i=1;i<br;i++){
            m=max.getPlostina();
            n=niza[i].getPlostina();
            if(n>m) max=niza[i];
        }
        return max;
    }
    int brojNaElementi(){
        return br;
    }
};

template<class T>
void printMnozestvo(Mnozestvo<T> M){
    for(int i=0;i<M.brojNaElementi();i++)
        M.prikaziElement(i);
}

int main()
{
    Mnozestvo<Kvadrat> kvadrati(5);
    Mnozestvo<Pravoagolnik> pravoagolnici(5);
    Mnozestvo<Krug> krugovi(5);
    int izbor;
    cout<<"Napravi izbor"<<endl;
    cout<<"0 - Dodadi pravoagolnik"<<endl;
    cout<<"1 - Dodadi kvadrat"<<endl;
    cout<<"2 - Dodadi krug"<<endl;
    cout<<"3 - Prikazi go mnozestvoto pravoagolnici"<<endl;
    cout<<"4 - Prikazi go mnozestvoto kvadrati"<<endl;
    cout<<"5 - Prikazi go mnozestvoto krugovi"<<endl;
    cout<<"6 - Prikazi najgolemi elementi"<<endl;
    cout<<"7 - Prikazi broj na elementi vo mnozestvata"<<endl;
    cout<<"8 - Kraj"<<endl;
    cin>>izbor;
    while(izbor>=0 && izbor<=7){
        if(izbor==0){
            int a, b;
            cout<<"Vnesi gi dvete strani na pravoagolnikot"<<endl;
            cin>>a>>b;
            Pravoagolnik P(a, b);
            pravoagolnici.dodadiElement(P);
        }else if(izbor==1){
            int a;
            cout<<"Vnesi ja stranata na kvadratot:"<<endl;
            cin>>a;
            Kvadrat K(a);
            kvadrati.dodadiElement(K);
        }else if(izbor==2){
            int r;
            cout<<"Vnesi go radiusot na krugot:"<<endl;
            cin>>r;
            Krug K(r);
            krugovi.dodadiElement(K);
        }else if(izbor==3){
            printMnozestvo(pravoagolnici);
        }else if(izbor==4){
            printMnozestvo(kvadrati);
        }else if(izbor==5){
            printMnozestvo(krugovi);
        }else if(izbor==6){
            cout<<"Pravoagolnik so najgolema povrsina:"<<endl;
            Pravoagolnik P=pravoagolnici.maxElement();
            P.print();
            cout<<"Kvadrat so najgolema povrsina:"<<endl;
            Kvadrat K=kvadrati.maxElement();
            K.print();
            cout<<"Krug so najgolema povrsina:"<<endl;
            Krug Kr=krugovi.maxElement();
            Kr.print();
        }else if(izbor==7){
            cout<<"Mnozestvo pravoagolnici ima "<<pravoagolnici.brojNaElementi()<<" elementi"<<endl;
            cout<<"Mnozestvo kvadrati ima "<<kvadrati.brojNaElementi()<<" elementi"<<endl;
            cout<<"Mnozestvo krugovi ima "<<krugovi.brojNaElementi()<<" elementi"<<endl;
        }
        cout<<"Napravi izbor"<<endl;
        cout<<"0 - Dodadi pravoagolnik"<<endl;
        cout<<"1 - Dodadi kvadrat"<<endl;
        cout<<"2 - Dodadi krug"<<endl;
        cout<<"3 - Prikazi go mnozestvoto pravoagolnici"<<endl;
        cout<<"4 - Prikazi go mnozestvoto kvadrati"<<endl;
        cout<<"5 - Prikazi go mnozestvoto krugovi"<<endl;
        cout<<"6 - Prikazi najgolemi elementi"<<endl;
        cout<<"7 - Prikazi broj na elementi vo mnozestvata"<<endl;
        cout<<"8 - Kraj"<<endl;
        cin>>izbor;
    }
    return 0;
}
