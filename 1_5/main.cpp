#include <iostream>

using namespace std;

template<class T>
class Array{
private:
    T *array;
    int size;
public:
    Array(int s=10){
        array=new T[s];
        size=s;
    }
    void putElement(int i, T element){
        array[i]=element;
    }
    T popElement(int i){
        return array[i];
    }
    ~Array(){
        delete [] array;
    }
};


int main()
{
    Array<int> A(10);
    int el;
    cout<<"Enter the integer array:"<<endl;
    for(int i=0;i<10;i++){
        cin>>el;
        A.putElement(i,el);
    }
    for(int i=0;i<10;i++){
        int element=A.popElement(i);
        cout<<element<<" ";
    }
    cout<<endl;

    Array<double> B(10);
    double e;
    cout<<"Enter the double array:"<<endl;
    for(int i=0;i<10;i++){
        cin>>e;
        B.putElement(i,e);
    }
    for(int i=0;i<10;i++){
        double element=B.popElement(i);
        cout<<element<<" ";
    }
    return 0;
}
