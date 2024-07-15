#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define size 52

int main()
{
    int n, niza[size];
    cout<<"Vnesi go brojot na igraci:"<<endl;
    cin>>n;
    while(size%n!=0){
        cout<<"Vnesi soodveten broj na igraci"<<endl;
        cin>>n;
    }

    // broevi od  1-13 se karti od A-K i forma srce
    // broevi od  14-26 se karti od A-K i forma dijamant
    // broevi od  27-39 se karti od A-K i forma detelina
    // broevi od  40-52 se karti od A-K i forma list
    for(int i=0;i<size;i++){
        niza[i]=i+1;
    }

    vector<int> spil(niza,niza+size);
    random_shuffle(spil.begin(),spil.end());
    vector<int>::const_iterator iterator=spil.begin();

    cout<<"Izmesanite spil se:"<<endl;
    while(iterator!=spil.end()){
        cout<<*iterator<<" ";
        iterator++;
    }

    int br_karti_igrac=52/n;
    int karti[br_karti_igrac];
    int sum, max=0, pobednik=0;

    iterator=spil.begin();
    cout<<"\n\nPodeleni karti na sekoj od igracite:"<<endl;
    for(int i=1;i<=n;i++){
        sum=0;
        for(int j=0;j<br_karti_igrac;j++){
            karti[j]=*iterator;
            iterator++;
        }
        cout<<"\nIgrac "<<i<<":"<<endl;
        for(int j=0;j<br_karti_igrac;j++){
            if(karti[j]>=1 && karti[j]<=13){ //srce
                cout<<karti[j]<<" srce"<<endl;
                sum=sum+karti[j]*2; //ako kartite srce se brojat dvojno, inaku: sum+=karti[j]
            }
            if(karti[j]>13 && karti[j]<=26){ //dijamant
                cout<<"dijamant"<<endl;
                cout<<karti[j]-13<<" dijamant"<<endl;
                sum+=karti[j]-13;
            }
            if(karti[j]>26 && karti[j]<=39){ //detelina
                cout<<karti[j]-26<<" detelina"<<endl;
                sum+=karti[j]-26;
            }
            if(karti[j]>39 && karti[j]<=52){ //list
                cout<<karti[j]-39<<" list"<<endl;
                sum+=karti[j]-39;
            }
        }
        cout<<"Zbir na kartite na igrac "<<i<<": "<<sum<<"\n";
        if(sum>max){
            max=sum;
            pobednik=i;
        }
    }
    cout<<"Pobednik e igrac: "<<pobednik<<" so zbir na kartite "<<max<<endl;
    return 0;
}
