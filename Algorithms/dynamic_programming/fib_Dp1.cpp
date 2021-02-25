#include<iostream>
using namespace std;
long long int a[100]={0},k[100]={0};

long long int dp(int n){                // Tabulation bottom-up approach

    for(int i=2;i<=100;i++){
    a[i]=a[i-1]+a[i-2];
    }
   return a[n];
}
long long int dp2(int n){                 // Memoization Top-bottom approach

    if(n==1 || n==0)
        return n;
    else if(a[n]!=0){
        return a[n];
    }
    a[n]=dp2(n-1)+dp2(n-2);

   return a[n];
}
long long int recurr(int n){
    if(n==0 || n==1){
        return n;
    }
    return recurr(n-1)+recurr(n-2);
}
int main(){
    a[0]=0;
    a[1]=1;
    k[0]=0;
    k[1]=1;
    int n;
    cin>>n;
    cout<<dp(n)<<endl;
    cout<<dp2(n)<<endl;
    cout<<recurr(n);

return 0;
}
