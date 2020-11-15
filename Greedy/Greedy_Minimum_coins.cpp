#include<iostream>
using namespace std;
int coins(int n){
    int c=0;
    while(n>0){
        if(n>=10){
            n-=10;
            
         }
         else if(n>=5){
             n-=5;
             
         }
         else{
             n-=1;
         }
         c+=1;
    }
    return c;
}
int main(){
    int n;
    cin>>n;
    cout<<coins(n);
    
    return 0;
}