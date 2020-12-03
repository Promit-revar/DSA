#include<iostream>
#include<vector>
#include<queue>
using namespace std;
template <typename T>
class treeNode{
    public:
    //as data can be of any type ...
    T data;
    //Here we specify treeNode<T> to denote that the datatype of children will be the same as their praents...Even if we don't write
    //<T> after treeNode it is there by default...
    vector<treeNode<T> *> ch;
    treeNode(T data){
        this->data=data;
    }
    ~treeNode(){
        for(int i=0;i<this->ch.size();i++){
            delete this->ch.at(i);
        }
    }
};
treeNode<int> * insertData(){
    
    int data,n;
    cout<<"Enter Data for root:"<<endl;
    cin>>data;

    treeNode<int> *root=new treeNode<int>(data);
    cout<<"Enter number of children:"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        treeNode<int> * child=insertData();
        root->ch.push_back(child);
    }
    return root;

}
treeNode<int> * insert_rowise(){
    cout<<"Enter root:"<<endl;
    int data,n;
    treeNode<int> *front;
    cin>>data;
    treeNode<int> *root=new treeNode<int>(data);
    
    queue<treeNode<int>* > Q;
    Q.push(root);
    while(!Q.empty()){
        front=Q.front();
        cout<<"Enter Number of children of "<<front->data<<": "<<endl;
        cin>>n;
        Q.pop();
        for(int i=1;i<=n;i++){
            cout<<"Enter "<<i<<"th child of "<<front->data<<": ";
            cin>>data;
            treeNode<int> *child=new treeNode<int>(data);
            front->ch.push_back(child);
            Q.push(child);

        }
    }
    return root;



}
int height(treeNode<int> * root,int h=0){
    h=1;
    for(int i=0;i<root->ch.size();i++){
        h+=height(root->ch.at(i),h);
    }
    return h;
}
void display(treeNode<int> * root){
    cout<<root->data<<" : ";
    for(int i=0;i<root->ch.size();i++)
       cout<<root->ch.at(i)->data<<", ";
    cout<<endl;
     for(int i=0;i<root->ch.size();i++){
        display(root->ch[i]);
     }
}
void rowise_print(treeNode<int> * root){
    treeNode<int> * front;
    queue<treeNode<int> * > que;
    que.push(root);
    while(!que.empty()){
        front=que.front();
        que.pop();
        cout<<front->data<<" : ";
        for(int i=0;i<front->ch.size();i++){
            cout<<front->ch.at(i)->data<<", ";
            que.push(front->ch.at(i));
        }
        cout<<endl;
    }

}
void print_depth(treeNode<int> * root, int d){
    if(d==0)
    {
        cout<<root->data<<" ";
        return;
    }
    for(int i=0;i<root->ch.size();i++)
    print_depth(root->ch.at(i),d-1);
    
}
int countNodes(treeNode<int> * root){
    int ans=1;
    for(int i=0;i<root->ch.size();i++){
        ans+=countNodes(root->ch.at(i));
    }
    return ans;
}
int countLeafNodes(treeNode<int> * root,int n){
    if(root->ch.empty())
    n+=1;
    for(int i=0;i<root->ch.size();i++)
    n=countLeafNodes(root->ch.at(i),n);
    return n;
}
int sumNode(treeNode<int>* root){
    int ans=root->data;
    for(int i=0;i<root->ch.size();i++){
        ans+=sumNode(root->ch.at(i));
    }
    return ans;
}
int maxData(treeNode<int> * root,int max){
      if(root->data>max){
          max=root->data;
      }
      for(int i=0;i<root->ch.size();i++){
          max=maxData(root->ch.at(i),max);
      }
      return max;
}
void postorder(treeNode<int> * root){
    
    for(int i=0;i<root->ch.size();i++){
        postorder(root->ch.at(i));
        
    }
    cout<<root->data<<" ";
}
void preorder(treeNode<int> * root){
    cout<<root->data<<" ";
    for(int i=0;i<root->ch.size();i++){
        preorder(root->ch.at(i));
    }
    
}
int main(){
    //Tree-> 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
    //Inserting data and creating nodes with data type int... the root has two children n1,n2 which does not contain any children 
    //further...
    /*
    Tree structure:
              1
             / \
            2   3
    */
    // treeNode<int> * root=new treeNode<int>(1);
    // treeNode<int> *n1=new treeNode<int>(2);
    // treeNode<int> *n2=new treeNode<int>(3);
    //connecting with parent...
    // root->ch.push_back(n1);
    // root->ch.push_back(n2);
    treeNode<int> * root=insert_rowise();
    //display(root);
    rowise_print(root);
    postorder(root);
    cout<<endl;
    preorder(root);
    //cout<<countNodes(root)<<endl;
    //cout<<sumNode(root)<<endl;
    //cout<<maxData(root,INT_MIN)<<endl;
    //cout<<height(root)<<endl;
    //print_depth(root,3);
    //cout<<countLeafNodes(root,0)<<endl;
    delete root;
    return 0;
}