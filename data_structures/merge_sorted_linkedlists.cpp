#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node * next;
   
    node(int data){
        this->data=data;
    }
    
};

class create{
    public:
    
    
    node * start=NULL;
    
    
void insert(int data){
        node * n1=new node(data);
        if(start ==NULL){
            start=n1;
            n1->next=NULL;
             
        }
        else{
            node *ptr=start;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=n1;
            n1->next=NULL;
           
        }
        
    }
    void display(){
        node *ptr=start;
        while(ptr->next!=NULL){
            cout<<ptr->data<<" -> ";
            ptr=ptr->next;
        }
        cout<<ptr->data<<endl;
    }
};

int main(){
    create c;
    c.insert(2);
    c.insert(3);
    c.insert(5);
    c.insert(8);
    c.display();
    create b;
    b.insert(1);
    b.insert(4);
    b.insert(7);
    b.insert(9);
    b.display();
    create bc;
    //cout<<b.start->next->data;
    while(c.start!=NULL && b.start!=NULL){
    
    if(c.start->data>b.start->data){
    bc.insert(b.start->data);
         //cout<<b.start->data;
         b.start=b.start->next;
         //cout<<"MC";
      }
        else{
        bc.insert(c.start->data);
         c.start=c.start->next;
         //cout<<"MC";
      }
     }
     if(c.start==NULL){
         while(b.start!=NULL){
              bc.insert(b.start->data);
        
         b.start=b.start->next;
         }
     }
     else{
         bc.insert(c.start->data);
         c.start=c.start->next;
     }
     bc.display();
    return 0;
}