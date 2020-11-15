#include<iostream>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin>>n;
    ll k=0,sum=0;
    ll a[100000];
    if(n==1){
        cout<<1<<endl;
        cout<<1;
    }
    else{
    for(ll i=1;i<n;i++){

        if(n-(sum+i)>i){
          sum+=i;
          a[k]=i;
          k++;
        }
        else{
            a[k]=n-sum;
            k++;
            cout<<k<<endl;
            break;

        }
    }
    for(int i=0;i<k;i++){
        cout<<a[i]<<" ";
    }
    }
    return 0;
}