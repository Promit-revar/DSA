#include<iostream>
#include<cstdio>
#include<queue>
#include"Binary_tree.cpp"
//4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
using namespace std;
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
Binary_tree<int> * rowise(){
    cout<<"Enter root:"<<endl;
    int data;

    cin>>data;
    Binary_tree<int> * front;
    Binary_tree<int> * n1=new Binary_tree<int>(data);
     queue<Binary_tree<int>* > Q;
    Q.push(n1);
    while(!Q.empty()){
        front=Q.front();

        Q.pop();
        cout<<"Enter Left child of "<<front->data<<endl;
        cin>>data;
        Binary_tree<int> * L=new Binary_tree<int>(data);
        cout<<"Enter Right child of "<<front->data<<endl;
        cin>>data;
        Binary_tree<int> * R=new Binary_tree<int>(data);

        if(L->data==-1 && R->data==-1)
        {
            L=NULL;
            R=NULL;
        }
        else if(R->data==-1)
        {
            R=NULL;
            Q.push(L);
        }
        else if(L->data==-1)
        {
            L=NULL;
            Q.push(R);
        }
        else{
            Q.push(L);
            Q.push(R);
        }
        front->left=L;
        front->right=R;
    }
    return n1;

}
void print(Binary_tree<int> * root){
    cout<<root->data<<" : ";
    if(root->left==NULL){
        cout<<endl;
    }
    else if(root->right==NULL)
    cout<<endl;
    else{
    cout<<root->left->data<<","<<root->right->data<<endl;

    print(root->left);
    print(root->right);
    }
}
node* explorerL(Binary_tree<int> * root){
    node * n1=new node(root->data);
    if(root->left==NULL && root->right==NULL){
        n1->next=NULL;
        return n1;
    }
    if(root->right!=NULL){
    n1->next=explorerL(root->right);
    return n1;
    }
    if(root->left!=NULL ){
    node *n2=explorerL(root->left);
    n2->next=n1;
    return n2;
    }

}
node * Bst_to_LL(Binary_tree<int> * root){
     if(root==NULL){
        return NULL;
     }
     /*Binary_tree<int> *Lefter=explorerL(root);
     cout<<Lefter->data;
     Binary_tree<int> *Righter=explorerR(root);
     cout<<"  "<<Righter->data;*/
     node* N=new node(root->data);
     node * head=explorerL(root->left);
     node * rightSide=explorerL(root->right);
     node * ptr=head;
     if(head==NULL){
     N->next=rightSide;
     return N;
     }
     while(ptr->next!=NULL){
     //cout<<ptr->data<<" ";
     ptr=ptr->next;
     }
     ptr->next=N;
     N->next=rightSide;
     return head;
}
int main(){
    Binary_tree<int> * root=rowise();
    print(root);
    node* N=Bst_to_LL(root);
    node * ptr=N;
    while(ptr!=NULL){
    cout<<ptr->data<<" ";
    ptr=ptr->next;
    }
    //cout<<"mc";
    return 0;
}
