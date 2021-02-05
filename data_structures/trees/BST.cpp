#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include"Binary_tree.cpp"
//4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
using namespace std;
class IBST{
   public:
   int mini,maxi;
   bool isBST;
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
Binary_tree<int> * Search(Binary_tree<int> * root,int s){
    if(root == NULL){
        return NULL;
    }
    else{

        if(root->data==s){
            return root;
        }
        else if(s>root->data){
             return Search(root->right,s);
        }
        else{
            return Search(root->left,s );
        }
    }
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
IBST isbst(Binary_tree<int> * root){
   IBST obj1;
   if(root==NULL){

      obj1.isBST=true;
      obj1.maxi=INT_MIN;
      obj1.mini=INT_MAX;
      return obj1;
   }
   IBST objleft=isbst(root->left);
   IBST objright=isbst(root->right);
   obj1.maxi=max(root->data,max(objleft.maxi,objright.maxi));
   obj1.mini=min(root->data,min(objleft.mini,objright.mini));
   obj1.isBST=(root->data>objleft.maxi)&&(root->data<=objright.mini)&&(objleft.isBST)&&(objright.isBST);
   return obj1;
}
void printRange(Binary_tree<int> * root,int l,int r){
     if(root==NULL){
        return ;
     }
     else{
        if(root->data<=r && root->data>=l){
            cout<<root->data<<" ";
        }
        printRange(root->left,l,r);
        printRange(root->right,l,r);
     }
}
Binary_tree<int> *constructBST(int a[],int strt,int ende){
      if(strt>ende){
        return NULL;
      }
      int m=(strt+ende)/2;
      Binary_tree<int> *root=new Binary_tree<int>(a[m]);
      root->left=constructBST(a,strt,m-1);
      root->right=constructBST(a,m+1,ende);
      return root;

}
int main(){
    Binary_tree<int> * root=rowise();
    print(root);
    //int s;
    //cout<<"Enter Search element:"<<endl;
    //cin>>s;
    //Binary_tree<int> * ele=Search(root,s);
    //cout<<ele->data<<endl;
    //printRange(root,2,6);
    //IBST obj=isbst(root);
    //cout<<obj.isBST;
    /*if(obj.isBST){
        cout<<"YES"<<endl;
    }
    else{
       cout<<"NO"<<endl;
    }*/
    int a[10];
    for(int i=0;i<10;i++){
        scanf("%d",&a[i]);
    }
    Binary_tree<int>* root2=constructBST(a,0,9);
    print(root2);
    return 0;

}
