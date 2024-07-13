#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    list<string> L1;
    list<string> L2;
    list<string> L3;
    string array1[]={"prva@gmail.com","povtorena1@gmail.com", "vtora@gmail.com"};
    string array2[]={"povtorena1@gmail.com", "treta@gmail.com", "povtorena2@gmail.com"};
    string array3[]={"povtorena2@gmail.com","cetvrta@gmail.com", "povtorena1@gmail.com"};

    L1.insert(L1.begin(),array1,array1+3);
    L2.insert(L2.begin(),array2,array2+3);
    L3.insert(L3.begin(),array3,array3+3);

    L1.sort();
    L2.sort();
    L3.sort();

    L1.merge(L2);
    L1.merge(L3);

    L1.unique();

    typename std::list<string>::const_iterator iterator;
    iterator=L1.begin();
    cout<<"Konecna lista:"<<endl;
    while(iterator!=L1.end()){
        cout<<*iterator<<endl;
        iterator++;
    }
    return 0;
}
