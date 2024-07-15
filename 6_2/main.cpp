#include <iostream>
#include <map>

using namespace std;

typedef map<int,int,greater<int>> Map;

int main()
{
    Map procesi;

    procesi.insert(Map::value_type(2,100)); // (prioritet, id)
    procesi.insert(Map::value_type(7,101));
    procesi.insert(Map::value_type(3,102));
    procesi.insert(Map::value_type(5,103));
    procesi.insert(Map::value_type(4,104));
    procesi.insert(Map::value_type(9,105));

    Map::const_iterator iterator=procesi.begin();

    cout<<"Redosled na opsluzuvanje: "<<endl;
    while(iterator!=procesi.end()){
        cout<<"Prioritet: "<<iterator->first<<endl;
        cout<<"ID: "<<iterator->second<<endl;
        iterator++;
    }

    return 0;
}
