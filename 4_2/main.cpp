#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    vector<char> string1;
    vector<char> string2;
    string s1, s2;
    int i;
    bool proverka;
    cout<<"Prv zbor:"<<endl;
    cin>>s1;
    cout<<"Vtor zbor:"<<endl;
    cin>>s2;

    for(i=0;i<s1.size();i++){
        string1.push_back(s1[i]);
    }
    for(i=0;i<s2.size();i++){
        string2.push_back(s2[i]);
    }

    if(string1.size()!=string2.size()){
        cout<<"Zborovite ne se anagrami"<<endl;
    }else{
        for(i=0;i<string1.size();i++){
            proverka=false; // na pocetok definirame deka karakterot string1[i] ne se pojavuva vo string2
            for(int j=0;j<string2.size();j++){
                if(string1[i]==string2[j]){
                    proverka=true;
                }
            }
            if(proverka==false){ // ako bide izminat ciklusot i ne bide najden soodvetniot karakter vo string2
                cout<<"Zborovite ne se anagrami"<<endl;
                break;
            }
        }
        if(proverka==true){
            for(i=0;i<string2.size();i++){ // soodvetno se izminuva i vtoriot string za da bideme sigurni i deka site bukvi od string2 gi ima vo string1
                proverka=false;
                for(int j=0;j<string1.size();j++){
                    if(string2[i]==string1[j])
                        proverka=true;
                }
                if(proverka==false){
                    cout<<"Zborovite ne se anagrami"<<endl;
                    break;
                }
            }
        }
        if(proverka==true){
            cout<<"Zborovite se anagrami"<<endl;
        }
    }
    return 0;
}
