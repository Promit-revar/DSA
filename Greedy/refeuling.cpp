#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
int main(){
    ll d ,c=0,x;
    int n,m;
    cin>>d;
    cin>>n;
    cin>>m;
    x=n;
    ll a[300];
    for(int i=0;i<m;i++){
        scanf("%d",&a[i]);
    }
    a[m]=d;
    int f=0;
    for(int i=1;i<=m;i++){
         if(a[i]-a[i-1]>n){
             cout<<-1;
             f=1;
             break;
         }

    }
    for(int i=1;i<m;i++){
         if(a[i]<=n){
             n-=(a[i]);

         }
         else{
            c++;
            n=x;
         }

    }
    if(f==0){
        cout<<c;
    }
    return 0;
}
