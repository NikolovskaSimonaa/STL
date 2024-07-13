#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main()
{
    deque<int> d;
    vector<int> v;

    d.push_front(1);
    d.push_front(2);
    d.push_back(4);
    d.push_back(3);

    cout<<"Deque:"<<endl;
    for(int i=0;i<d.size();i++){
        cout<<d[i]<<" ";
    }
    cout<<endl;

    v.push_back(d[3]);
    v.push_back(d[2]);
    v.push_back(d[1]);
    v.push_back(d[0]);

    cout<<"Vector:"<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    return 0;
}
