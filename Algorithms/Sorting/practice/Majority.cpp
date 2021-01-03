#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
typedef long long ll;
int main(){
    map<int,int> mp;
    int n;
    cin>>n;
    
    ll a[100000];
    for(int i=0;i<n;i++){
       scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        mp[a[i]]++;
    }
    int f=0;
    for(int i=0;i<n;i++){
        
       if(mp[a[i]]>n/2){
          cout<<1<<endl;
          f=1;
          break;
       }
        
    }
    if(f==0){
        cout<<0<<endl;
    }
    return 0;
}