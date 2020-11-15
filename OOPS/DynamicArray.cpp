#include<iostream>
class DynamicArray{
    int currIndex;
    int capacity;
    int *data;
    public:
    DynamicArray(){
    data=new int[5];
    currIndex=-1;
    capacity=5;
    }
    void add(int x){
    currIndex++;
    if(currIndex==capacity){
        capacity*=2;
        int *newData=new int[capacity];
        
        for(int i=0;i<currIndex;i++){
            newData[i]=data[i];
        }
        delete [] data;
        data=newData;
        data[currIndex]=x;
    }
    else{
        data[currIndex]=x;
    }
}
    int size(){
    return currIndex+1;
    }
    void display(){
        for(int i=0;i<=currIndex;i++){
            std::cout<<data[i]<<std::endl;
        }
    }
    void add(int x,int i){
        if(i<currIndex){
            data[i]=x;
        }
        else if(i==currIndex){
            add(x);
        }
        else{
            return;
        }
    }

};
//void DynamicArray::
