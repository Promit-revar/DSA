#include<iostream>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
int main(){
    ll n,m,k;
    cin>>n>>m;
   
    if(m==n){
        cout<<m;
    }else{
    //cout<<y<<endl;
    if(m>n){
    k=gcd(m,n);
    }
    else{
        k=gcd(n,m);
    }
    

    cout<<(m*n)/k;
    }
    return 0;
}