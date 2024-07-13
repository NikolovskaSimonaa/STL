#include <iostream>
#include <vector>

template<class T>
bool palindrom(const std::vector<T> v){
    typename std::vector<T>::const_iterator iterator;
    typename std::vector<T>::const_iterator reverse;
    iterator=v.begin();
    reverse=v.end();
    reverse--;
    while(iterator!=reverse){
        if(*iterator!=*reverse){
            return false;
        }
        iterator++;
        reverse--;
    }
    return true;
}


using namespace std;

int main()
{
    string s="abcba";
    vector<char> V(s.begin(), s.end());

    if(palindrom(V)==true){
        cout<<"Vektorot "<<s<<" e palindrom"<<endl;
    }else{
        cout<<"Vektorot "<<s<<" ne e palindrom"<<endl;
    }

    return 0;
}
