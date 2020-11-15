#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long a[n];
    long long max=0,u;
    long long k=1;
    vector<int> v;
    int r=0;
    while(r<27){
        v.push_back(rand()%100);
        r++;
    }
    for(auto i:v){
        cout<<i<<endl;
    }
    /*for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(max<a[i]){
            max=a[i];
            u=i;
        }

    }
    if(n==1){
        cout<<a[0];
    }
    else{
    k*=max;
    max=0;
    a[u]=0;
    for(int i=0;i<n;i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    cout<<k*max;
    }*/

    return 0;
}