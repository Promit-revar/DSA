#include<iostream>
#include<vector>

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
void display(treeNode<int> * root){
    cout<<root->data<<" : ";
    for(int i=0;i<root->ch.size();i++)
       cout<<root->ch.at(i)->data<<", ";
    cout<<endl;
     for(int i=0;i<root->ch.size();i++){
         display(root->ch[i]);
     }
}
int main(){
    //Inserting data and creating nodes with data type int... the root has two children n1,n2 which does not contain am=ny children 
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
    treeNode<int> * root=insertData();
    display(root);
    return 0;
}