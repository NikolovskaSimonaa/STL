#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Imenik{
private:
    string ime;
    string tel_br;
public:
    Imenik(string i, string t){
        ime=i;
        tel_br=t;
    }
    void print(){
        cout<<"Ime: "<<ime<<endl;
        cout<<"Telefonski broj: "<<tel_br<<endl;
    }
    friend bool operator<(Imenik &I1, Imenik &I2){
        if(I1.ime.compare(I2.ime)<0) return true;
        else return false;
    }
};


int main()
{
    vector<Imenik> niza;
    int n;
    cout<<"Broj na objekti vo klasata:"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        string ime, t;
        cout<<"Vnesi ime i telefonski broj:"<<endl;
        cin>>ime>>t;
        Imenik I(ime,t);
        niza.push_back(I);
    }
    for(int i=0;i<n;i++)
        niza[i].print();
    sort(niza.begin(),niza.end());
    cout<<"Po sortiranje:"<<endl;
    for(int i=0;i<n;i++)
        niza[i].print();
    return 0;
}
