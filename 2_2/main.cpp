#include <iostream>

using namespace std;

class Kvadrat{
private:
    int strana;
public:
    Kvadrat(int s=1){
        strana=s;
    }
    Kvadrat(Kvadrat &K){
        strana=K.strana;
    }
    int getPlostina(){
        return strana*strana;
    }
    void print(){
        cout<<"a=" << strana<<endl;
    }
    Kvadrat operator=(Kvadrat &K){
        strana=K.strana;
        return *this;
    }
};

class Pravoagolnik{
private:
    int sirina;
    int dolzina;
public:
    Pravoagolnik(int s=1, int d=1){
        sirina=s;
        dolzina=d;
    }
    Pravoagolnik(Pravoagolnik &P){
        sirina=P.sirina;
        dolzina=P.dolzina;
    }
    int getPlostina(){
        return dolzina*sirina;
    }
    void print(){
        cout<<"a=" <<dolzina<<" b="<<sirina<<endl;
    }
    Pravoagolnik operator=(Pravoagolnik &P){
        sirina=P.sirina;
        dolzina=P.dolzina;
        return *this;
    }
};

template<class T>
void sortirajPole(T *a, int size){
    for(int i=0;i<size-1;i++){
        for(int j=i;j<size;j++){
            if(a[i].getPlostina()>a[j].getPlostina()){
                T tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
        }
    }
}

template<class T>
void pecatiPole(T *a, int size){
    for(int i=0;i<size;i++)
        a[i].print();
}

int main()
{
    Kvadrat K[2]={Kvadrat(4),Kvadrat(3)};
    cout<<"Kvadrati:"<<endl;
    pecatiPole(K,2);
    sortirajPole(K,2);
    cout<<"Po sortiranje:"<<endl;
    pecatiPole(K,2);
    Pravoagolnik P[3]={Pravoagolnik(3,4),Pravoagolnik(2,4),Pravoagolnik(5,4)};
    cout<<"Pravoagolnici:"<<endl;
    pecatiPole(P,3);
    sortirajPole(P,3);
    cout<<"Po sortiranje:"<<endl;
    pecatiPole(P,3);
    return 0;
}
