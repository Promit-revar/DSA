#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
ll a[100000];
void seive(){
    //ll a[100000];
    for(ll i=0;i<100000;i++){
        a[i]=0;
    }
    for(ll i=2;i<sqrt(100000);i++){
            
        for(ll j=2*i;j<100000;j+=i){
            //if(j%i==0)
            a[j]=1;
            
            
            
            
        }
    }
    
        
}
int main(){
    
    
    seive();
    for(ll i=2;i<100000;i++){
        if(a[i]==0){
           cout<<i<<" ";
        }
        
    }
   
    return 0;
}