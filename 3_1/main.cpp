#include <iostream>

using namespace std;

template<class T>
class Zapis{
private:
    T x;
    T y;
    T z;
public:
    Zapis(T x1, T y1, T z1){
        x=x1;
        y=y1;
        z=z1;
    }
    void print(){
        cout<<"x="<<x<<endl;
        cout<<"y="<<y<<endl;
        cout<<"z="<<z<<endl;
    }
    T sum(){
        return x+y+z;
    }
};

template<class T>
int kontrolor(Zapis<T> z){
    if(z.sum()>10000)
        return 0;
    return 1;
}

int main()
{
    Zapis<int> Z1(500,600,700);
    Zapis<double> Z2(5000.5,600.6,7000.7);
    Z1.print();
    Z2.print();
    if(kontrolor(Z1)==0) cout<<"Sumata nadminuva 10000"<<endl;
    else cout<< "Sumata e vo granici na dozvolenoto"<<endl;
    if(kontrolor(Z2)==0) cout<<"Sumata nadminuva 10000"<<endl;
    else cout<< "Sumata e vo granici na dozvolenoto"<<endl;
    return 0;
}
