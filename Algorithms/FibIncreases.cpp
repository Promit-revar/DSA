#include<iostream>
using namespace std;
typedef long long ll;
int main(){
    ll m,n,a[10000];
    cin>>n>>m;
    a[0]=0;
    a[1]=1;
    if(m>n){
        for(ll i=2;i<m;i++){
        a[i]=a[i-1]+a[i-2];
        a[i]%=m;
    }
    cout<<a[n-1];
    }
    else{
        cout<<a[0]%m<<" "<<a[1]%m<<" ";
        //ll x=n%(2<<m);
    for(ll i=2;i<n;i++){
        a[i]=a[i-1]+a[i-2];
        a[i]%=m;
        cout<<a[i]<<" ";
    }
   // cout<<a[x-1]<<" "<<(2<<m-1);
    }
    return 0;
}