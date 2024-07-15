#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <numeric>

#define max 10000

bool even(int n){
    return n%2==0;
}

bool smaller2000(int n){
    return n<2000;
}

bool between2000and4000(int n){
    return n>=2000 && n<4000;
}

bool between4000and6000(int n){
    return n>=4000 && n<6000;
}

bool between6000and8000(int n){
    return n>=6000 && n<8000;
}

bool between8000and10000(int n){
    return n>=8000 && n<10000;
}

using namespace std;

int main()
{
    //srand(time(NULL));
    int array[max], sum;
    float average;
    for(int i=0;i<max;i++){
        array[i]=rand()%max;
    }
    vector<int> V(array,array+max);

    int result=count_if(V.begin(),V.end(),even);
    cout<<"Broj na parni broevi:"<<result<<endl;
    result=count_if(V.begin(),V.end(),smaller2000);
    cout<<"Broj na broevi vo pomali od 2000:"<<result<<endl;
    result=count_if(V.begin(),V.end(),between2000and4000);
    cout<<"Broj na broevi vo opseg [2000, 4000):"<<result<<endl;
    result=count_if(V.begin(),V.end(),between4000and6000);
    cout<<"Broj na broevi vo opseg [4000, 6000):"<<result<<endl;
    result=count_if(V.begin(),V.end(),between6000and8000);
    cout<<"Broj na broevi vo opseg [6000, 8000):"<<result<<endl;
    result=count_if(V.begin(),V.end(),between8000and10000);
    cout<<"Broj na broevi vo opseg [8000, 10000):"<<result<<endl;
    sum=accumulate(V.begin(),V.end(),0);
    average=(float)sum/10000;
    cout<<"Sredna vrednost na elementite:"<<average<<endl;

    return 0;
}
