#include <iostream>
#include <cstdlib>
#include <exception>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));
    int n1=(rand()%1000)+1;
    int n2=(rand()%1000)+1;
    vector<int> V1(n1);
    vector<int> V2(n2);
    cout<<"Solzina na vektor 1:"<<V1.size()<<endl;
    cout<<"Dolzina na vektor 2:"<<V2.size()<<endl;

    for(int i=0;i<n2;i++)
        V2[i]=i;
    try{
        if(V2.size()>V1.size()){
            throw -1;
        }
        copy(V2.begin(),V2.end(),V1.begin());
        vector<int>::const_iterator iterator=V1.begin();
        while(iterator!=V1.end()){
            cout<<*iterator<<" ";
            iterator++;
        }
        cout << endl;
    }catch (int){
        cout<<"Dolzinata na vektor 2 e pogolema od dolzinata na vektor 1"<<endl;
    }

    return 0;
}
