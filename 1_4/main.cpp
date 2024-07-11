#include <iostream>
#include <iomanip>

using namespace std;

template<class T>
void printArray(T *array, int size){
    for(int i=0;i<size;i++)
        cout<<array[i]<<" ";
    cout<<endl;
}

void printArray(int *array, int size){
    for(int i=0;i<size;i++){
        cout<<setw(4)<<array[i];
        if((i+1)%4==0)
            cout<<endl;
    }
}

int main()
{
    int array[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    printArray(array,12);
    cout<<endl;
    return 0;
}
