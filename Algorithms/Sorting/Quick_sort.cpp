#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
void print(ll *,int,int );
int partition(ll *a,int l,int r){
    int s=(l+r)/2;
    ll temp;
    //cout<<l<<" -l"<<endl;
    temp=a[l];
    a[l]=a[s];
    a[s]=temp;
    int k=l+1,h=r;
    ll pivot=a[l];
    //cout<<pivot<<endl;
    while(k<=h){
        if(a[k]<=pivot){
            k++;
        }
        else if(a[h]>pivot){
            h--;

        }
        else{
            temp=a[k];
            a[k]=a[h];
            a[h]=temp;
            k++;
            h--;
        }
    }
    a[l]=a[h];
    a[h]=pivot;
    //print(a,l,r);
    return h;
}
void print(ll *a,int l,int r){
    for(int i=l;i<=r;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void quickSort(ll *a,int l, int r){
    if(l>=r){
        return;
    }
    
    int m=partition(a,l,r);
    quickSort(a,l,m-1);
    quickSort(a,m+1,r);
}
int main(){
    int n;
    cin>>n;
    ll a[100000];
    for(int i=0;i<n;i++){
        scanf("%ld",&a[i]);
    }
    quickSort(a,0,n-1);
    print(a,0,n-1);
    return 0;
}