#include<iostream>
class initalizationList{
    public:
    int a;
    int const b;
    int &g;
    //Thus to assign values to const and reference variables of a class we use initalization list within a constructor...
    initalizationList(int x,int a) : b(x),a(a),g(this->a){
        

    }

};
int main(){
    initalizationList obj(5,6);
    std::cout<<obj.a<<" "<<obj.b<<" "<<obj.g;
    return 0;
}