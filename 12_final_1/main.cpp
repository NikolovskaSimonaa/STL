#include <iostream>
#include <cstring>

using namespace std;

template<class T>
class Pole{
public:
    T *niza;
    int dolzina;
    Pole(int d){
        dolzina=d;
        niza=new T[dolzina];
    }
    void vnesiElementi(){
        for(int i=0;i<dolzina;i++){
            cin>>niza[i];
        }
    }
};

template<class T>
T max(Pole<T> P){
    T max=P.niza[0];
    for(int i=1;i<P.dolzina;i++){
        if(P.niza[i]>max){
            max=P.niza[i];
        }
    }
    return max;
}

string max(Pole<string> P){
    string max=P.niza[0];
    for(int i=1;i<P.dolzina;i++){
        if(max.compare(P.niza[i])<0){
            max=P.niza[i];
        }
    }
    return max;
}


int main()
{
    Pole<int> a(5);
    Pole<char> b(5);
    Pole<string> c(5);
    cout<<"Vnesi pole od celobrojni vrednosti:"<<endl;
    a.vnesiElementi();
    cout<<"Vnesi pole od karakteri:"<<endl;
    b.vnesiElementi();
    cout<<"Vnesi pole od stringovi:"<<endl;
    c.vnesiElementi();

    cout<<"Maksimalen element vo pole a: "<<max(a)<<endl;
    cout<<"Maksimalen element vo pole b: "<<max(b)<<endl;
    cout<<"Maksimalen element vo pole c: "<<max(c)<<endl;

    return 0;
}
