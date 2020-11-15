#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
   int n;
    cin>>n;
    ll sum=0;
    int a[1000],b[1000];

    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    sort(a,a+n);
    sort(b,b+n);
    for(int i=0;i<n;i++){
        //cout<<a[i]<<" "<<b[i]<<endl;
       sum+=(a[i]*b[i]);
    }
    cout<<sum;
    return 0;
}