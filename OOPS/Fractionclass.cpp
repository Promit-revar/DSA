#include<iostream>
class fraction{
   private:
   int num,deno;
   public:
   int Gcd(int a,int b){
       if(b==0){
           return a;
       }
       Gcd(b,a%b);
    }
   fraction(int num,int deno){
       this->num=num;
       this->deno = deno;
   }
   void add(fraction const &f2){  // Passing by reference aviod call to copy constructor and declaring it const prevent changes into the main block
      num=num*f2.deno+f2.num*deno;
      deno*=f2.deno;
      simp();
   }
   void simp(){
       int gcd = Gcd(num,deno);
       num /= gcd;
       deno /= gcd;
       std::cout<<num<<"/"<<deno<<endl;
       
   }
   void mul(fraction const &f2){
       num*=f2.num;
       deno*=f2.deno;
       simp();

   }
};