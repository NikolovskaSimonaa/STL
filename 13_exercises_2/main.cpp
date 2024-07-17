#include <iostream>
#include <vector>
#include <cstring>
#include <cctype>

using namespace std;

class Znak{
private:
    char c;
    bool pogoden;
public:
    Znak(char c, bool p){
        this->c=c;
        pogoden=p;
    }
    char getZnak(){
        return c;
    }
    bool getPogoden(){
        return pogoden;
    }
    void ePogoden(){
        pogoden=true;
    }
};

int main()
{
    int pogoduvanja=5; // igracot ima 5 sansi za pogoduvanje na zborot
    Znak Z[7]={Znak('b',false),Znak('e',false),Znak('s',false),Znak('i',false),
                   Znak('l',false),Znak('k',false),Znak('a',false)};
    vector<Znak> ZborZaPogoduvanje(Z,Z+7);
    while(pogoduvanja>0){
        cout<<"\nVnesi zbor za pogoduvanje:"<<endl;
        string zbor;
        cin>>zbor;
        try{
            for(int i=0;i<zbor.length();i++)
                if(!isalpha(zbor[i]) || isupper(zbor[i]))
                    throw true;
        }catch(bool){
            cout<<"Nevalidna forma na zborot"<<endl;
            exit(1);
        }
        int count=0;
        vector<Znak>::iterator iterator=ZborZaPogoduvanje.begin();
        for(int i=0;i<zbor.length();i++){
            if(iterator==ZborZaPogoduvanje.end()){
                break;
            }
            bool proveri=iterator->getPogoden();
            char c=iterator->getZnak();
            if(proveri==true){ //proveri dali veke bil pogoden
                count++;
                cout<<c;
            }else{ //proveri dali sega e pogoden
                if(c==zbor[i]){
                    cout<<c;
                    iterator->ePogoden();
                    count++;
                }else{
                    cout << "-";
                }
            }
            iterator++;
        }
        while(iterator!=ZborZaPogoduvanje.end()){
            cout<<"-";
            iterator++;
        }
        if(count==zbor.length()){
            cout<<"\nBravo!"<<endl;
            return 0;
        }
        pogoduvanja--;
    }
    cout<<"\nPoveke srekja sledniot pat"<<endl;
    return 0;
}
