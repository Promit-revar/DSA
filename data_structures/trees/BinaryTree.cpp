#include<iostream>
#include<queue>
#include<vector>
#include"Binary_tree.cpp"
using namespace std;

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
Binary_tree<int> * TakeInput(){
    int data;
    cout<<"Enter Data :"<<endl;
    cin>>data;
    
    if(data==-1){
        
        return NULL;
    }else{
        Binary_tree<int> * n1=new Binary_tree<int>(data);
        Binary_tree<int> * leftchild=TakeInput();
        Binary_tree<int> * rightchild=TakeInput();
        n1->left=leftchild;
        n1->right=rightchild;
        return n1;
    }
   
}
int CountNumberOfNodes(Binary_tree<int> * root){
    if(root==NULL)
    {
        return 0;
    }
    return 1+ CountNumberOfNodes(root->left)+ CountNumberOfNodes(root->right);
    
}
void inorder(Binary_tree<int> * root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(Binary_tree<int> * root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
Binary_tree<int> * ConstructTree(int * pre,int * in,int pree,int ins,int ine,int pres){
    if(pres>pree){
        return NULL;
    }
    //This method is only used when there are no duplicates in tree...
    int data;
    data=pre[pres];
    Binary_tree<int> * root=new Binary_tree<int>(data);
    int ri=-1;//index of root in inorder as it comes after left...
    for(int i=ins;i<=ine;i++){
          if(in[i]==data){
              ri=i;
              break;
          }
    }
    
    int lpres=pres+1;//As just after root comes left in preorder as root->left->right...
    int lins=ins;// left comes in start of inorder expresion as left->root->right...
    int line=ri-1;// finding the end of the left subtree in inorder expression...
    int lpree=line-lins+lpres;// having the number of elements in left subtree by getting line-lins we can subtract lpres from this number to get lpree...
    int rpres=lpree+1;// As right subtree starts just after left subtree in preorder...
    int rpree=pree;//Right subtree is the last in preorder hence it ends at the end of preorder array...
    int rins=ri+1;// Right subtree starts just after root in inorder expression thus ri+1 marks it's begining... 
    int rine=ine;// Right subtree ends with end of inorder array...
    
    root->left=ConstructTree(pre,in,lpree,lins,line,lpres);//Calling for building left subtree...
    root->right=ConstructTree(pre,in,rpree,rins,rine,rpres);//Calling for building right subtree...
    
    return root;
}
int height(Binary_tree<int> * root){
    if(root==NULL){
        return 0;
    }
    return 1+(max(height(root->left),height(root->right)));
}
int diameter(Binary_tree<int> * root){
    if(root==NULL)
    return 0;
    int x=height(root->right)+height(root->left);
    int y=diameter(root->left);
    int z=diameter(root->right);
    return max(x,max(y,z));
}
int main(){
   //1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
    Binary_tree<int> * root=rowise();
    print(root);
    cout<<CountNumberOfNodes(root)<<endl;
    inorder(root);//left->root->right
    cout<<endl;
    preorder(root);// root->left->right
    //Building a tree ...
    int in[]={4,2,5,1,8,6,9,3,7};//inorder of a tree
    int pre[]={1,2,4,5,3,6,8,9,7};//preorder of a tree
    
    Binary_tree<int> *root=ConstructTree(pre,in,9,0,9,0);// building a tree from inorder and preorder...
    print(root);
    cout<<diameter(root);
    delete root;
    return 0;
}