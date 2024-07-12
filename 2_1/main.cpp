#include <iostream>

using namespace std;

template<class T>
T sumElements(T *a, int start, int end, T init=T()){
    init=a[start]+a[end];
    return init;
}

int main()
{
    int a[]={5,3,4,7,2,8,1,10,6,9};
    int sum=sumElements(a,0,9);
    cout<<"Result: "<<sum<<endl;
    return 0;
}
