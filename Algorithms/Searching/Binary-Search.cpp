#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
void binarySearch(ll *a,int n,int key){
    int l=0,r=n-1;
    while(l<=r){
        int m=(l+r)/2;
        if(key>a[m]){
            l=m+1;
        }
        else if(key<a[m]){
            r=m-1;
        }
        else{
            cout<<m<<" ";
            break;
        }
    }
    if(l>r){
        cout<<-1<<" ";
    }
}
int main(){
    int n,k;
    ll a[100000],b[100000];
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    cin>>k;
    for(int i=0;i<k;i++){
        scanf("%d",&b[i]);
    }
    for(int i=0;i<k;i++){
        binarySearch(a,n,b[i]);
    }
    return 0;
}