#include<iostream>
#include<string>
#include"designation.cpp"   //including file containing object data
using namespace std;
class employee{
    public:
    int empId;
    string name;
    void filler();


};
void employee::filler(){            //defining function for class data to access private properties of the class
    cin>>empId>>name;

}
void data::filler(){
    cin>>desgn>>age>>salary>>sex>>marital_status;
}
void data::display(){
    cout<<desgn<<" "<<age<<" "<<salary<<" "<<sex<<" "<<marital_status<<endl;
}
void mdata::change(){
    cin>>desgn>>age>>salary>>sex>>marital_status;
}
int main(){
    employee obj1;   // statically creating a object for class employee
    mdata ob;   // Object for another class in diffrent file
    obj1.filler();
    cout<<obj1.empId<<" "<<obj1.name<<endl;
    ob.filler();
    ob.change();
    ob.display();
    employee * obj2=new employee; //creating object dynamically
    obj2->filler();   // calling function of class for which object was assigned dynamically
    cout<<obj2->empId<<" "<<obj2->name;   //attributes being referred by dynamic object of class
    return 0;
}
