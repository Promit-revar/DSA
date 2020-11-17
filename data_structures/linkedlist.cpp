#include<iostream>
int count =0;
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
    node *n1=new node(data);
    count++;
    if(start==NULL){
       //std::cout<<n1.data;
       start = n1;
    
       n1->next=NULL;
       return;
    }
    else{
        //std::cout<<n1.data;
        n1->next=start;
        start=n1;
        return;
    }
}
void insert_at_end(int data){
    node *n1=new node(data);
    count++;
    if(start==NULL){
        
        start=n1;
        
        n1->next=NULL;
        return;
    }
    else{
        
        node *ptr=start;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=n1;
        n1->next=NULL;
        return;

    }
}
void insert_in_middle(int pos,int data){
     
    if(start==NULL && pos>1){
        std::cout<<"Enter valid position..."<<std::endl;
         
    }
    else if(pos>count+1){
        std::cout<<"Enter valid position..."<<std::endl;
        
    }
    else{
        node *n1=new node(data);
        count++;
        node *ptr=start;
        
        for(int i=1;i<pos-1; i++){
            ptr=ptr->next;
        };
        if(ptr->next==NULL){
            ptr->next=n1;
            n1->next=NULL;
        }
        else{
            n1->next=ptr->next;
            ptr->next=n1;
        }
    }
}
 void  display(){
     node *ptr=start;
    while(ptr->next!=NULL){
        std::cout<<ptr->data<<" -> ";
        ptr=ptr->next;
    }
     std::cout<<ptr->data;
     std::cout<<std::endl;
    
}
void delete_node(int pos){
    if(start==NULL)
    {
        std::cout<<"Empty "<<std::endl;
        return ;
    }
    else if(pos>count){
        std::cout<<"Enter valid Position to delete"<<std::endl;
        return;
    }
    else{
        count--;
        node *ptr=start;
        if(pos==1){
            start=ptr->next;
            delete ptr;
        }
        else if(pos==count){
            for(int i=1;i<pos-1;i++){
              ptr=ptr->next;
              //std::cout<<"MC";
        }
        node * x=ptr->next;
        ptr->next=NULL;

        delete x;
        }
        else{
        for(int i=1;i<pos-1;i++){
              ptr=ptr->next;
              //std::cout<<"MC";
        }
        
        node *x=ptr->next;
        ptr->next=x->next;
        delete x;
        }
    }

}
node* find_mid(){
    node *slw=start;
    node *fst=slw->next;
    if(count&1){
        while(fst!=NULL){
            slw=slw->next;
            fst=fst->next->next;
        }
    }
    else{
        while(fst->next!=NULL){
            slw=slw->next;
            fst=fst->next->next;
        }
    }
    return slw;
}
int main(){
    
    insert_at_begining(1);
     
    insert_at_begining(2);
    insert_at_begining(3);
    insert_at_begining(4);
 
    insert_at_end(10);
    insert_in_middle(3,17);
    display();
    //delete_node(6);
    //display();
    std::cout<<find_mid()->data;
  
    
    return 0;
}