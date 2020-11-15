#include<iostream>
using namespace std;
class Student{
    public:
    string name;
    int roll,age,grade;
    //default constructor has no return type, no arguments and is called at the time of obl=ject creation 
    //if explicitly mentioned then that is called or else internally created one gets called
    Student(){
        cin>>roll>>age>>grade>>name;
    }
    //parameterized constructor bears parameters ...
    Student(string name,int roll,int age,int grade){
        this->name=name;
        this->roll=roll;
        this->grade=grade;
        this->age=age;
        //this keyword stores the reference of the object that is created and that calls the given constructor...
    }
    //copy constructor created explicitly...
    //Here we use pass by reference in parameter to avoid calling of copy constructor for constructing copy of main variable and
    //we also define it const to avoid change that has been made to object reflect to main block.. 
    Student(Student const &s){
        //Deep copy
        this->name=new char[strlen(s.name)+1];
        strcpy(this->name,name);
        //Shallow copy
        this->roll=roll;
        this->grade=grade;
        this->age=age;
    }
    //destructor which destroys the object memory i.e deallocates it...
    //it doesnot have any arguments...
    ~Student(){
       cout<<"Destructor called";
    }


};
int main(){
    //calling default constructor...
    Student s1;
    cout<<s1.name<<" "<<s1.age<<endl;
    //calling parameterized constructor...
    Student *s2=new Student("promit",25,20,12);
    cout<<s2->name<<" "<<s2->age<<endl;
    //copy contructor ...
    //Student s3(s1);
    //Or
    Student *s4=new Student(*s2);
    //or
    //Student s4=s2;
    Student s3;
    cout<<s4->name<<" "<<s4->age<<endl;
    //We can also use '=' operator also inorder to copy values being assigned by the constructor of other object to our object...
    s3=s1;
    cout<<s3.name<<" "<<s3.age<<endl;
    return 0;
}
/*
NOTE :- Constructor gets called only once for a particular object and that too when object is created
        The difference between copy constructor and '=' operator is the copy constructor gets called only when an obejct is created
        while '=' operator copies the values any number of times for any object after it has been created. 
        */