#include<iostream>
#include<vector>
#include<queue>
#include"Binary_tree.cpp"
using namespace std;
vector<int> * pathTo(Binary_tree<int> * root,int data){
      if(root==NULL){
        return NULL;
      }
      if(root->data==data){
        vector<int>* path0=new vector<int>();
        path0->push_back(root->data);
        return path0;
      }
      //new vector<int>()
      vector<int>* path1=pathTo(root->left,data);
      if(path1!=NULL){
        path1->push_back(root->data);
        return path1;
      }
      vector<int>* path2=pathTo(root->right,data);
      if(path2!=NULL){
        path2->push_back(root->data);
        return path2;
      }
      else{
      return NULL;
      }

}
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
int main(){
   Binary_tree<int> * root=rowise();
   print(root);
   int a;
   cout<<"Enter Node to which path you want:"<<endl;
   cin>>a;
   vector<int> * uzi=pathTo(root,a);
   if(uzi==NULL){
    cout<<"NO PATH FOUND"<<endl;
   }
   else{
    for(int i=0;i<uzi->size();i++){
        cout<<uzi->at(i)<<" ";
    }
    cout<<endl;
   }
   return 0;
}
