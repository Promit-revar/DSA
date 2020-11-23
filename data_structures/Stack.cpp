#include<iostream>
class stack{
    int top;
    int size;
    int *s;
    public:
    stack(int size){
        this->size=size;
        s=new int[size];
        top=-1;
    }
    void push(int data){
        if(isfull()){
           std::cout<<"Stack is Full"<<std::endl;
           return;
        }
        s[++top]=data;
    }
    bool isfull(){
        return top==size-1;
    }
    bool isempty(){
        return top==-1;
    }
    void pop(){
        if(isempty()){
            std::cout<<"Stack is empty!!"<<std::endl;
            return;
        }
        top--;
    }
    int peek(){
        if(isempty()){
            return top;
        }
        return s[top];
    }
};
int main(){
    stack s1(10);
    s1.pop();
    s1.push(2);
    s1.pop();
    s1.push(2);
    s1.push(31);
    s1.push(244);
    s1.push(43);
    s1.pop();
    std::cout<<s1.peek()<<std::endl;
    
    return 0;

}