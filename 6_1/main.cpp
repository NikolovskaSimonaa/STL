#include <iostream>
#include <map>
#include <cstring>

using namespace std;

class Uplata{
private:
    string ime;
    int uplata;
public:
    Uplata(string i, int u){
        ime=i;
        uplata=u;
    }
    string getIme(){
        return ime;
    }
    void print()const{
        cout<<"Ime na stedacot: "<<ime<<endl;
        cout<<"Uplata: "<<uplata<<endl;
    }
};

typedef multimap<int,Uplata,std::less<int>> mmap;

int main()
{
    mmap banka;
    int izbor;
    cout<<"Napravi izbor:"<<endl;
    cout<<"0 - Dodaj uplata"<<endl;
    cout<<"1 - Prikazi uplati za stedac"<<endl;
    cout<<"2 - Kraj"<<endl;
    cin>>izbor;
    while(izbor==0 || izbor==1){
        if(izbor==0){
            string i;
            int u, kod;
            cout<<"Vnesi go imeto na stedacot:"<<endl;
            cin>>i;
            cout<<"Vnesi ja uplatata:"<<endl;
            cin>>u;
            Uplata U(i,u);
            cout<<"Vnesi kod na uplatata"<<endl;
            cin>>kod;
            typedef pair<int,Uplata> uplata;
            banka.insert(uplata(kod,U));
        }
        else{
            string i;
            cout<<"Vnesi go imeto na stedacot:"<<endl;
            cin>>i;
            mmap::const_iterator iterator=banka.begin();
            while(iterator!=banka.end()){
                Uplata tmp=iterator->second;
                if(tmp.getIme().compare(i)==0){
                    iterator->second.print();
                }
                iterator++;
            }
        }
        cout<<"Napravi izbor:"<<endl;
        cout<<"0 - Dodaj uplata"<<endl;
        cout<<"1 - Prikazi uplati za stedac"<<endl;
        cout<<"2 - Kraj"<<endl;
        cin>>izbor;
    }
    return 0;
}
