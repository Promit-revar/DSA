#include<iostream>
class student{
    // static keyword before datatype is used to denote that the variable or data member is static which means that it is not a 
    //class attribute but is a class variable and stays there for each object created and it can be changed by any object but the effect
    //of that chage will reflect for every object ...
   static int totalStudents;
   public:
   int rollNumber=20;
   int age=23;
   //the const keyword denotes constant function which does not change the value og the property in a class .
   //These functions are accessable even by const objects...  
   int getRoll() const{
       return this->rollNumber;
   }
   int getAge() const{
       return age;
   }
   //As many objects are created those many times satic variable gets incremented...
   student(){
       totalStudents++;
   }
   //Static functions can only access static variables and should not be used for non-static variables and can be called by any object...
   static int getStudents(){
       return totalStudents;
   }
};
//Static data memebers must be allocated outside the class using '::' operator 
int student :: totalStudents=0;
int main(){
    student s1;
    s1.age=12;
    s1.rollNumber=20;
    student const s2;
    std::cout<<s2.getAge()<<std::endl;
    std::cout<<s1.getStudents();
    return 0;
}