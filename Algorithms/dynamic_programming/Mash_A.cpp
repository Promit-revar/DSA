#include<iostream>
using namespace std;

long long int solve(long long int n){
    long long int f[n+1];
   f[0]=1;
   f[1]=0;
   for(int i=2;i<=n;i++){
    f[i]=2*f[i-2];
   }
   return f[n];
}

int main(){
    long long int n;
    cin>>n;
    cout<<solve(n)<<endl;
return 0;
}
