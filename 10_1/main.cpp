#include <iostream>
#include <stdlib.h>
#include <memory>

using namespace std;

class Klasa{
private:
    int x;
public:
    Klasa(int x){
        cout<<"Povikan konstruktor na objekt od tip Klasa, so parametar x="<<x<<endl;
        this->x=x;
    }
    void setX(int x){
        this->x=x;
    }
    int getX(){
        return x;
    }
    ~Klasa(){
        cout<<"Povikan destruktor na objekt od tip Klasa, so parametar x="<<x<<endl;
    }
};


int main()
{
    int n;
    srand(time(NULL));
    n=rand()%6;
    Klasa objekt(n);
    if(objekt.getX()<=3){
        Klasa *ptr=&objekt;
        ptr->setX(10);
        cout<<"Vrednosta za x pristapena preku pokazuvacot: "<<ptr->getX()<<endl;
    }

    /* Vo ovoj del ne mozeme da napravime pristapuvanje preku pokazuvac na sledniov nacin:
       cout<<"Vrednosta za x pristapena preku pokazuvacot: "<<ptr->getX()<<endl;
       bidejki pokazuvacot ne e definiran vo ovoj del od programata, no objektot seuste postoi. */

    cout<<"Vrednosta za x pristapena preku objektot: "<<objekt.getX()<<endl;

    return 0;
}
