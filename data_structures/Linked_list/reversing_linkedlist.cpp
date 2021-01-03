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
    node * tail=NULL;
    
void insert(int data){
        node * n1=new node(data);
        if(start ==NULL){
            start=n1;
            tail=n1;
            n1->next=NULL;
             
        }
        else{
            node *ptr=start;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=n1;
            n1->next=NULL;
           tail=n1;
        }
        
    }
    void display(){
        node *ptr=start;
        while(ptr->next!=NULL){
            cout<<ptr->data<<" -> ";
            ptr=ptr->next;
        }
        cout<<ptr->data<<endl;
       // tail=ptr;
    }
};
node * reverse(node *start){
    if(start==NULL || start->next==NULL){
        return start;
    }
    node *ptr=reverse(start->next);
    node *end=start->next;
    end->next=start;
    start->next=NULL;
    return ptr;
}
void reverser(node *start,node *tail){
    if(tail==start){
        tail->next=NULL;
        
        return;
    }
    node *x=start;
    node *ptr=tail;
   
        while(x->next!=tail){
            x=x->next;
        }
         
        x->next=NULL;
        ptr->next=x;
       
        ptr=x;
        
    
        //cout<<ptr->data<<"  "<<tail->data<<endl;
        reverser(start,ptr);
    

}

int main(){
    create c;
    c.insert(2);
    c.insert(3);
    c.insert(5);
    c.insert(8);
    c.insert(5);
    c.insert(7);
    c.insert(5);
    c.insert(6);
    c.insert(23);
    c.insert(11);
    c.display();
    //reversing linked list in O(n^2) recurrsively...
    reverser(c.start,c.tail);
    node *ptr=c.start;
    c.start=c.tail;
    c.tail=ptr;
    //reversing linkedlist in O(n) recurrsively...
    c.start=reverse(c.start);
    c.display();
    //reversing linkedlist O(n) iteratively...
    node *curr=c.start;
    node *prev=NULL;
    node *nx=curr->next;
    while(nx!=NULL){
        curr->next=prev;
        prev=curr;
        curr=nx;
        nx=nx->next;
    }
    curr->next=prev;
    c.start=curr;
    c.display();
    // cout<<c.tail->data<<" "<<c.start->data;
    // for()
    return 0; 
}
