#include<iostream>
#include"Binary_tree.cpp"
using namespace std;
//7 4 2 6 3 1 5
class BinarySearchTree{
private:
    Binary_tree<int> * root;
    bool hasdata(int data,Binary_tree<int> * root){
        if(root==NULL){
            return false;
        }
        if(root->data==data){
            return true;
        }
        if(data<root->data)
        return hasdata(data,root->left);
        if(data>root->data)
        return hasdata(data,root->right);
    }
    Binary_tree<int> *insertNode(int d,Binary_tree<int> * root){

        if(root==NULL){
            cout<<"added :"<<d<<endl;
            Binary_tree<int> * root=new Binary_tree<int>(d);
            return root;

        }

       else if(d>=root->data)
        {
       /* if(root->right==NULL){
            Binary_tree<int> * R=new Binary_tree<int>(d);
            root->right=R;
            return root;

        }
                return insertNode(d,root->right);*/
                root->right=insertNode(d,root->right);





        }
        else if(d<root->data)
        {
        /* if(root->left==NULL){
            Binary_tree<int> * L=new Binary_tree<int>(d);
            root->left=L;
            return root;

        }

            return insertNode(d,root->left);*/
            root->left=insertNode(d,root->left);

        }


    }
    Binary_tree<int> * finder(Binary_tree<int> * root){
        if(root->left->left==NULL){
            return root;
        }
        return finder(root->left);
    }
    Binary_tree<int> * delNode(Binary_tree<int> * root,int data){
          if( root==NULL){
            return NULL;
          }
          if(root->data==data){
                //cout<<"andere0"<<endl;
            if(root->right==NULL && root->left==NULL)
            {    cout<<"andere1"<<endl;
                //root=NULL;
                Binary_tree<int> * t=this->root;
                Binary_tree<int> * w=t;
                while(t->left->data!=data && t->right->data!=data){
                    //t=t->left;
                    if(t->data>data){
                        t=t->left;
                    }
                    else{
                        t=t->right;
                    }

                }
                if(t->data>data){
                    t->left=NULL;
                }
                else{
                    t->right=NULL;
                }

                delete root;
                return this->root;
            }
            else if(root->right!=NULL && root->left==NULL){
                //cout<<"andere2"<<endl;
                root->data=root->right->data;
                root->right=root->right->right;
                root->left=root->right->left;
                delete root->right;
                //cout<<this->root->data<<root->data;
                return this->root;


            }
            else if(root->right==NULL && root->left != NULL){
                //cout<<"andere3"<<endl;
                root->data=root->left->data;
                root->right=root->left->right;
                root->left=root->left->left;
                delete root->left;
                //cout<<this->root->data<<root->data;
                return this->root;
            }
            else{
                //cout<<"andere4"<<endl;
                if(root->right->left==NULL){
                    root->data=root->right->data;
                    root->right=root->right->right;
                    delete root->right;
                    return this->root;
                }
                Binary_tree<int> * rt=finder(root->right);
                //cout<<rt->left->data<<" "<<root->data<<endl;
                root->data=rt->left->data;
                //cout<<rt->left->data<<" "<<root->data<<endl;

                delete rt->left;
                rt->left=NULL;
                return this->root;
            }
          }
          if(data> root->data){
            return delNode(root->right,data);
          }
          else{
            return delNode(root->left,data);
          }
    }
    void printout(Binary_tree<int>* t){
          if(t==NULL){
            return;
          }
          cout<<t->data<<" : ";
          Binary_tree<int> *ptr=t;
          if(t->left!=NULL){
            cout<<t->left->data<<",";
          }
          if(t->right!=NULL){
            cout<<t->right->data<<",";
          }
          cout<<endl;
          printout(t->left);
          printout(t->right);

    }

public:
    void ins(int data){

        Binary_tree<int> * rt=insertNode(data,root);

        if(root==NULL)
        root=rt;

    }
    void del(int data){
        cout<<root->data<<endl;
        root=delNode(root,data);
        //O(h) work...
    }

    bool SearchData(int data){
        return hasdata(data,root);
    }
    BinarySearchTree(){
    root=NULL;
    }
    ~BinarySearchTree(){
    delete root;
    }
    void print(){
       printout(root);

    }
};

int main (){
    BinarySearchTree obj;
    int n;
    cout<<"Enter Number of nodes to be inserted: ";
    cin>>n;
    n-=1;
    while(n--){
        cout<<endl<<"Insert data";
        int d;
        cin>>d;
        obj.ins(d);
    }
    cout<<"Resultant Binary search tree:"<<endl;
    obj.print();
    cout<<"data to be deleted : ";

    cin>>n;
    obj.del(n);
    cout<<"Resultant Binary search tree:"<<endl;
    obj.print();
  return 0;
}
/* BST WORKS BEST WHEN TREE IS BALANCED...
if tree has height = h= n=> number of nodes then the operations of BST will be O(n) hence not so much efficeint...
     1
      \
       2
        \              => Unbalanced BST
         3
          \
           4
BALANCED BST IS THAT WHERE DIFFERENCE BETWEEN LEFT HEIGHT AND RIGHT HEIGHT IS ATMOST 1:

              3
             / \
            2   5
           /   / \
          1   4   6
