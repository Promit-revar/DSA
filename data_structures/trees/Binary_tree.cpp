template<typename T>
class Binary_tree{
    public:
    T data;
    Binary_tree<int> * right;
    Binary_tree<int> * left;
    Binary_tree(T data){
          this->data=data;
          right=NULL;
          left=NULL;
    }
    ~Binary_tree(){
        delete left;
        delete right;
    }
};