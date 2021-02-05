#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
class Binary_tree{
    public:
    int data;
    Binary_tree* left;
    Binary_tree* right;
    bool left_thread;
    bool right_thread;

    Binary_tree(){
         left=NULL;
         right=NULL;
         left_thread=false;
         right_thread=false;
    }
};
Binary_tree * insertion(){
    int data;
      cout<<"Enter root"<<endl;
      cin>>data;
      Binary_tree * root=new Binary_tree;
      root->data=data;
      queue<Binary_tree *> q;
      q.push(root);
      Binary_tree * ptr=root;
      while(!q.empty()){
        cout<<"Enter Left child of "<<ptr->data<<endl;
        cin>>data;
        if(data==-1){
            q.front()->left_thread=true;
            q.front()->left=ptr;
        }
        else{
        Binary_tree * nodeL=new Binary_tree;
        nodeL->data=data;
        q.push(nodeL);
        }
        cout<<"Enter Right child of "<<ptr->data<<endl;
        cin>>data;
        if(data==-1){
            q.front()->right_thread=true;
            q.front()->right=ptr;
        }
        else{
        Binary_tree * nodeR=new Binary_tree;
        nodeR->data=data;
        q.push(nodeR);
        }
        q.pop();
        ptr=q.front();
      }
      return root;

}
void print(Binary_tree * root){
    if(root==NULL )
        return;
    cout<<root->data<<"  "<<endl;

    print(root->left);
    print(root->right);
}
void inorder(Binary_tree * root){
     if(root==NULL){
        return;
     }
     cout<<root->data<<" ";
     inorder(root->left);
     inorder(root->right);
}
int main(){
    Binary_tree * root=insertion();
    //print(root);
    inorder(root);
    return 0;
}
