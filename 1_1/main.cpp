#include <iostream>

using namespace std;

template<class T>
void sort(T *array, int size){
    int i,j;
    for(i=0;i<size-1;i++){
        for(j=i+1;j<size;j++){
            if(array[i]>array[j]){
                T tmp=array[i];
                array[i]=array[j];
                array[j]=tmp;
            }
        }
    }
    cout<<"Sorted array: ";
    for(i=0;i<10;i++)
        cout<<array[i]<<" ";
    cout<<endl;
}

int main()
{
    int aInt[10],i;
    double aDouble[10];
    cout<<"Enter the integer array:"<<endl;
    for(i=0;i<10;i++){
        cin>>aInt[i];
    }
    cout<<"Enter the double array:"<<endl;
    for(i=0;i<10;i++){
        cin>>aDouble[i];
    }
    sort(aInt,10);
    sort(aDouble,10);
    return 0;
}
