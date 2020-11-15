#include<iostream>
using namespace std;
typedef long long ll;
int main(){
    ll a[1000000],n;
    cin>>n;
    a[0]=1;
    a[1]=1;

    for(ll i=2;i<n;i++){
        a[i]=a[i-1]+a[i-2];
        a[i]%=10;
        //cout<<a[i]<<endl;
    }
    cout<<a[n-1];
    return 0;
}