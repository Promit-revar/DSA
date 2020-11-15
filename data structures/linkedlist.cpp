#include<iostream>

class node{
    public:
    node *next;
    int data;
    // static int count=0;
    
    node(int data){
        this->data=data;
        
        // count++;
    }
    // void insert_at_begining(node,int);
    // void insert_at_middle(int pos,int x);
    // void insert_at_end(node,int);
    // void display(node);

};
node * start=NULL;
void insert_at_begining(int data){
    //std::cout<<start<<std::endl;
    node n1(data);
    
    if(start==NULL){
       //std::cout<<n1.data;
       start = &n1;
    
       n1.next=NULL;
       return;
    }
    else{
        //std::cout<<n1.data;
        n1.next=start;
        start=&n1;
        return;
    }
}
void insert_at_end(int data){
    node n1(data);
    
    if(start==NULL){
        
        start=&n1;
        
        n1.next=NULL;
        return;
    }
    else{
        
        node *ptr=start;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=&n1;
        n1.next=NULL;
        return;

    }
}
// void  display(){
    
// }
int main(){
    
    insert_at_begining(1);
     //std::cout<<start;
    insert_at_begining(2);
    insert_at_begining(3);
    insert_at_begining(4);
    std::cout<<start;
//     insert_at_end(10);
    
   node *ptr=start;
    while(ptr->next!=NULL){
        std::cout<<ptr->data<<" -> ";
        ptr=ptr->next;
    }
     std::cout<<ptr->next;
    
    return 0;
}