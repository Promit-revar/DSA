#include<iostream>
class node{
    public:
    int data;
    node * prev;
    node * next;
    

    node(int data){
       this->data=data;
       prev=NULL;
       next=NULL;

    }
     
};
class create{
    public:
    node * start=NULL;
    node *tail=NULL;
void insert_at_begining(int data){
        node * n1=new node(data);
        if(start==NULL){
            start=n1;
            n1->prev=NULL;
            n1->next=NULL;
            tail=n1;
        }
        else{
            start->prev=n1;
            n1->next=start;
            
            start=n1;
        }
    }
    void insert_at_end(int data){
        node * n1=new node(data);
        if(start==NULL){
            start=n1;
            n1->prev=NULL;
            n1->next=NULL;
            tail=n1;
        }
        
        else{
        tail->next=n1;
        n1->prev=tail;
        tail=n1;
        }
    }
    void insert_at_pos(int data,int pos)
    {
        node * n1=new node(data);
        if(start==NULL && pos!=1){
            std::cout<<"Invalid Position..."<<std::endl;
            return;
        }
        node* ptr=start;
        int c=1;
        while(ptr!=NULL){
             if(pos==c){
                ptr->prev->next=n1;
                n1->prev=ptr->prev;
                ptr->prev=n1;
                n1->next=ptr;
                break;

             }
             //std::cout<<c<<pos;
             
             c++;
             ptr=ptr->next;
            //std::cout<<ptr->data;

        }
       // std::cout<<c;
        if(pos==c){
           tail->next=n1;
            n1->prev=tail;
            tail=n1;
        }
    }
    void display(node * start){
        node *ptr=start;
        if(ptr->next==NULL){
            while(ptr!=NULL){
                std::cout<<ptr->data<<" -> ";
                ptr=ptr->prev;
            }
             std::cout<<"NULL"<<std::endl;
        }
        else if(ptr->prev==NULL){
            while(ptr!=NULL){
                std::cout<<ptr->data<<" -> ";
                ptr=ptr->next;
            }
            std::cout<<"NULL"<<std::endl;
        }

    }
};
int main(){
    create c;
    c.insert_at_end(1);
    c.insert_at_begining(2);
    c.insert_at_end(3);
    c.insert_at_pos(5,4);
     c.display(c.start);
    c.display(c.tail);
    return 0;

}