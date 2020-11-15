#include<iostream>
class Complex{
    int real,imag;
    public:
    Complex(int real=0,int imag=0){
        this->real=real;
        this->imag=imag;
    }
    // operator overloading function where operator keyword along with the operator sign ... 
    Complex operator + (Complex const &C2){
        Complex Cnew;
        Cnew.real=this->real+C2.real;
        Cnew.imag=imag+C2.imag;
        return Cnew;
    }
    void display(){
        std::cout<<this->real<<" + "<<this->imag<<"i"<<std::endl;
    }
    // the '&' after the return type denotes that we are returning by reference and hence ++(++C1) can operate as we make the changes
    //to out object properties and no temporary system buffer get's created for this as where the outer operation applies rather the 
    //outer operations applies to the object itself as we are returning that reference... 
    Complex& operator++(){
        real+=1;
        //here * indicates that we are returning values of the block that is being pointed by 'this' keyword and not it's address only...
        return *this;
        
    }
    //if int argument is provided for ++ operator then the ++ is post increment operator...
    Complex operator++(int){
        Complex Cnew;
        Cnew.real=real;
        Cnew.imag=imag;
        real=real+1;
        return Cnew;

    }

    
    Complex& operator+=(Complex const &C2){
        real+=C2.real;
        imag+=C2.imag;
        return *this;

    }
};
int main(){
    //inorder to work with operator overloading both the objects should be static or both dynamic won't work is any one is static and 
    //other is dynamic
    Complex C1(5,7);
    
    Complex C2(0,3);
    
    // Calling the overloaded operator
    Complex C3=C1 + C2;
    //Calling Unary overloaded operator...
    // ++(++C1);
    // C1.display();
    //Complex C4=C1++;
    (C1+=C2)+=C2;
    C1.display();
    //C4.display();
    return 0;
}
/* NOTE:
Almost all operators can be overloaded except few. Following is the list of operators that cannot be overloaded.

   . (dot) 
   :: 
   ?: 
   sizeof */

/* 
Important points about operator overloading
1) For operator overloading to work, at least one of the operands must be a user defined class object.

2) Assignment Operator: Compiler automatically creates a default assignment operator with every class. 
The default assignment operator does assign all members of right side to the left side and works fine most of the cases (this behavior is same as copy constructor).

3) Conversion Operator: We can also write conversion operators that can be used to convert one type to another type.
Overloaded conversion operators must be a member method.Other operators can either be member method or global method.

4) Any constructor that can be called with a single argument works as a conversion constructor, 
means it can also be used for implicit conversion to the class being constructed.
*/