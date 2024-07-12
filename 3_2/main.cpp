#include <iostream>
#include <cstring>

using namespace std;

template<class T>
class Mnozestvo{
private:
    static int br_elementi;
    int counter;
    T *array;
public:
    Mnozestvo(int br=1, int c=0){
        br_elementi=br;
        counter=c;
        array=new T[br_elementi];
    }
    void dodadiElement(T e){
        if(counter<br_elementi){
            array[counter]=e;
            counter++;
        }
    }
    void prikaziElementi(){
        for(int i=0;i<counter;i++)
            cout<<array[i]<<" ";
        cout<<endl;
    }
    T max(){
        T max=array[0];
        for(int i=1;i<counter;i++){
            if(max<array[i])
                max=array[i];
        }
        return max;
    }
    string max(int){
        string max=array[0];
        for(int i=1;i<counter;i++){
            if(max.compare(array[i])==-1)
                max=array[i];
        }
        return max;
    }
    int brojNaElementi(){
        return counter;
    }
    ~Mnozestvo(){
        delete [] array;
    }
};

template <class T> int Mnozestvo<T>::br_elementi = 5;

int main()
{
    Mnozestvo<int> A(5);
    Mnozestvo<double> B(5);
    Mnozestvo<string> C(5);
    int izbor;
    cout<<"Napravi izbor:"<<endl;
    cout<<"0 - Dodaj element vo A"<<endl;
    cout<<"1 - Dodaj element vo B"<<endl;
    cout<<"2 - Dodaj element vo C"<<endl;
    cout<<"3 - Prikazi go A"<<endl;
    cout<<"4 - Prikazi go B"<<endl;
    cout<<"5 - Prikazi go C"<<endl;
    cout<<"6 - Prikazi najgolemi elementi"<<endl;
    cout<<"7 - Prikazi broj na elementi vo mnozestvata"<<endl;
    cout<<"8 - Kraj"<<endl;
    cin>>izbor;
    while(izbor>=0 && izbor<=7){
        if(izbor==0){
            int e;
            cout<<"Vnesi element:"<<endl;
            cin>>e;
            A.dodadiElement(e);
        }else if(izbor==1){
            double e;
            cout<<"Vnesi element:"<<endl;
            cin>>e;
            B.dodadiElement(e);
        }else if(izbor==2){
            string e;
            cout<<"Vnesi element:"<<endl;
            cin>>e;
            C.dodadiElement(e);
        }else if(izbor==3){
            cout<<"Mnozestvo A: ";
            A.prikaziElementi();
        }else if(izbor==4){
            cout<<"Mnozestvo B: ";
            B.prikaziElementi();
        }else if(izbor==5){
            cout<<"Mnozestvo C: ";
            C.prikaziElementi();
        }else if(izbor==6){
            int max1=A.max();
            cout<<"Maksimalen element vo A: "<<max1<<endl;
            double max2=B.max();
            cout<<"Maksimalen element vo B: "<<max2<<endl;
            string max3=C.max(0);
            cout<<"Maksimalen element vo C: "<<max3<<endl;
        }else if(izbor==7){
            cout<<"Mnozestvo A ima "<<A.brojNaElementi()<<" elementi"<<endl;
            cout<<"Mnozestvo B ima "<<B.brojNaElementi()<<" elementi"<<endl;
            cout<<"Mnozestvo C ima "<<C.brojNaElementi()<<" elementi"<<endl;
        }
        cout<<"Napravi izbor:"<<endl;
        cout<<"0 - Dodaj element vo A"<<endl;
        cout<<"1 - Dodaj element vo B"<<endl;
        cout<<"2 - Dodaj element vo C"<<endl;
        cout<<"3 - Prikazi go A"<<endl;
        cout<<"4 - Prikazi go B"<<endl;
        cout<<"5 - Prikazi go C"<<endl;
        cout<<"6 - Prikazi najgolemi elementi"<<endl;
        cout<<"7 - Prikazi broj na elementi vo mnozestvata"<<endl;
        cout<<"8 - Kraj"<<endl;
        cin>>izbor;
    }
    return 0;
}
