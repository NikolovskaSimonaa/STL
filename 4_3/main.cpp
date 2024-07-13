#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<string> tekst;
    string zbor;

    cout<<"Vnesi tekst(| za kraj)"<<endl;
    cin>>zbor; //vnesuvanje zbor po zbor
    while(zbor!="|"){
        tekst.push_back(zbor);
        cin>>zbor; //vnesuvanje zbor po zbor
    }

    sort(tekst.begin(),tekst.end());

    cout<<"Zborovi vo tekstot:"<<endl;
    for(int i=0;i<tekst.size();i++){
        int pecati=1; //dali treba da se pecati zborot
        for(int j=0;j<i;j++){ // da ne se pecati poveke pati istiot zbor
            if(tekst[j].compare(tekst[i])==0){
                pecati=0;
                break;
            }
        }
        if(pecati==1){
            cout<<tekst[i]<<endl;
        }
    }

    return 0;
}
