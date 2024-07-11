#include <iostream>

using namespace std;

template<class T>
void printArray(T *array, int size){
    for(int i=0;i<size;i++)
        cout<<array[i]<<" ";
    cout<<endl;
}

template<class T>
int printArray(T *array, int size, int lowSubscript, int highSubscript){
    if(lowSubscript>=size || highSubscript>=size){
        return 0;
    }else{
        int count=0;
        for(int i=lowSubscript;i<=highSubscript;i++){
            cout<<array[i]<<" ";
            count++;
        }
        cout<<endl;
        return count;
    }
}

int main()
{
    const int aCount=5;
    const int bCount=7;
    const int cCount=6;

    int a[aCount]={1, 2, 3, 4, 5};
    double b[bCount]={1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    char c[cCount]="HELLO";

    //Version a)
    cout<<"A: ";
    printArray(a, aCount);
    cout<<endl;
    cout<<"B: ";
    printArray(b, bCount);
    cout<<endl;
    cout<<"C: ";
    printArray(c, cCount);
    cout<<endl;

    //Version b)
    cout<<"A: ";
    int r=printArray(a,aCount,0,2);
    if(r==0){
        cout<<"Incorrect index"<<endl;
    }
    cout<<"B: ";
    r=printArray(b,bCount,1,5);
    if(r==0){
        cout<<"Incorrect index"<<endl;
    }
    cout<<"C: ";
    r=printArray(c,cCount,2,4);
    if(r==0){
        cout<<"Incorrect index"<<endl;
    }
    return 0;
}
