#include<iostream>
using namespace std;
#include "Fractionclass.cpp"
#include "DynamicArray.cpp"
int main(){
    // fraction f1(10,2);
    // fraction f2(15,4);
    // f1.add(f2);
    // f1.mul(f2);
    DynamicArray a;
    for(int i=0;i<5;i++){
        a.add(i);
    }
    a.add(23);
    a.add(23);
    a.add(23);
    a.add(23);
    a.add(23);

    a.add(23);
    a.add(123,10);
    a.add(172,6);
    a.display();
    cout<<a.size()<<endl;
    return 0;
}