#include <iostream>
#include <cstring>

using namespace std;

template<class T>
class Lica{
private:
    char *ime_prezime;
    char *mat_br;
    int vozrast;
    char *adresa;
    T kod;
public:
    Lica(char *i=(char *)"", char *mbr=(char *)"", int v=0, char *adr=(char *)"", T k=NULL){
        ime_prezime=new char[strlen(i)];
        strcpy(ime_prezime,i);
        mat_br=new char[strlen(mbr)];
        strcpy(mat_br,mbr);
        vozrast=v;
        adresa=new char[strlen(adr)];
        strcpy(adresa,adr);
        kod=k;
    }
    void print(){
        cout<<"Ime i prezime: "<<ime_prezime<<endl;
        cout<<"Maticen broj: "<<mat_br<<endl;
        cout<<"Vozrast: "<<vozrast<<endl;
        cout<<"Adresa: "<<adresa<<endl;
        cout<<"Kod: "<<kod<<endl;
    }
};

template<class T>
void pecatiPole(T *a, int size){
    for(int i=0;i<size;i++)
        a[i].print();
}

int main()
{
    Lica<int> Vraboteni[5];
    Lica<char> Klienti[5];
    int izbor, br_vraboteni=0, br_klienti=0;
    cout<<"Napravi izbor:"<<endl;
    cout<<"0 - Dodadi vraboten"<<endl;
    cout<<"1 - Dodadi klient"<<endl;
    cout<<"2 - Pecati vraboteni"<<endl;
    cout<<"3 - Pecati klienti"<<endl;
    cout<<"4 - Kraj"<<endl;
    cin>>izbor;

    while(izbor>=0 && izbor<=3){
        if(izbor==0){
            char i[40], mbr[10], adr[20];
            int v, kod;
            cin.ignore();
            cout<<"Ime i prezime:"<<endl;
            gets(i);
            cout<<"Maticen broj:"<<endl;
            cin>>mbr;
            cout<<"Vozrast:"<<endl;
            cin>>v;
            cin.ignore();
            cout<<"Adresa:"<<endl;
            gets(adr);
            cout<<"Kod:"<<endl;
            cin>>kod;
            Vraboteni[br_vraboteni]=Lica(i, mbr, v, adr, kod);
            br_vraboteni++;
        }else if(izbor==1){
            char i[40], mbr[10], adr[20];
            int v;
            char kod;
            cin.ignore();
            cout<<"Ime i prezime:"<<endl;
            gets(i);
            cout<<"Maticen broj:"<<endl;
            cin>>mbr;
            cout<<"Vozrast:"<<endl;
            cin>>v;
            cin.ignore();
            cout<<"Adresa:"<<endl;
            gets(adr);
            cout<<"Kod:"<<endl;
            cin>>kod;
            Klienti[br_klienti]=Lica(i, mbr, v, adr, kod);
            br_klienti++;
        }else if(izbor==2){
            pecatiPole(Vraboteni, br_vraboteni);
        }else if(izbor==3){
            pecatiPole(Klienti, br_klienti);
        }
        cout<<"Napravi izbor:"<<endl;
        cout<<"0 - Dodadi vraboten"<<endl;
        cout<<"1 - Dodadi klient"<<endl;
        cout<<"2 - Pecati vraboteni"<<endl;
        cout<<"3 - Pecati klienti"<<endl;
        cout<<"4 - Kraj"<<endl;
        cin>>izbor;
    }
    return 0;
}

