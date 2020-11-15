#include<iostream>
#include<cstring>
class student{
    char *name;
    int age;
    public:
    student(char*name,int age){
        //this->name= name; //Shallow copy where we just provide pointer to the array instead of building a new array if changes are made
        //in the main array those will be reflected in s1 too..

        //deep copy to prevent above scenario...
        this-> name=new char[strlen(name)+1];
        strcpy(this->name,name);
        this->age=age;

    }
    void display(){
        std::cout<<name<<" "<<age<<std::endl;
    }
};
int main(){
    char name[]="Promit";
    student s1(name,20);
    s1.display();
    name[0]='K';
    student s2(name,24);
    s2.display();
    s1.display();// will print name as Kromit as we changed the array and made shallow copy in the constructor
                 // Or will print name as promit as we have done deep copy in our constructor...
    return 0;
}