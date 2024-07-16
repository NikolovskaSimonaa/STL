#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int n, m;
    cout<<"Vnesi do koja vrednost da se tabelira vrednosta za i:"<<endl;
    cin>>n;
    cout<<"Vnesi vrednost za sirina na kolonite na tabelata:"<<endl;
    cin>>m;
    cout<<left<<setw(m)<<"i"<<setw(m)<<"i*i"<<setw(m)<<"sqrt(i)"<<setw(m)<<"pow(i,(float)1/3)"<<endl;
    for(int i=1;i<=n;i++){
        cout<<left<<setw(m)<<i<<setw(m)<<i*i<<setw(m)<<setprecision(2)<<sqrt(i)<<setw(m)<<setprecision(2)<<pow(i,(float)1/3)<<endl;
    }

    return 0;
}
