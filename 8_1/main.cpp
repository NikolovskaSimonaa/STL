#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

#define vrednost_na_bod 100

using namespace std;

class Vraboten{
private:
    string ime;
    int bodovi;
public:
    Vraboten(string i="Nepoznato", int b=0){
        ime=i;
        bodovi=b;
    }
    int getPlata(){
        return bodovi*vrednost_na_bod;
    }
    void print() const{
        cout<<"Ime: "<<ime<<endl;
        cout<<"Bodovi: "<<bodovi<<endl;
    }
    friend bool operator<(Vraboten &V1, Vraboten &V2){
        if(V1.bodovi<V2.bodovi) return true;
        else return false;
    }
    friend int operator+(int sum, Vraboten V){
        sum+=V.getPlata();
        return sum;
    }
};

int main()
{
    int n;
    cout<<"Kolku vraboteni ima vo firmata:"<<endl;
    cin>>n;
    vector<Vraboten> vraboteni(n);
    for(int i=0;i<n;i++){
        string ime;
        int bodovi;
        cout<<"Vnesi ime:"<<endl;
        cin>>ime;
        cout<<"Vnesi bodovi za ovoj mesec:"<<endl;
        cin>>bodovi;
        vraboteni[i]=Vraboten(ime, bodovi);
    }
    sort(vraboteni.begin(),vraboteni.end());
    vector<Vraboten>::const_iterator iterator=vraboteni.begin();
    int sum=accumulate(vraboteni.begin(),vraboteni.end(),0);
    while(iterator!=vraboteni.end()){
        iterator->print();
        iterator++;
    }
    cout<<"Vkupna suma potrebna za da se isplati mesecna plata za cela firma: "<<sum<<endl;
    return 0;
}
