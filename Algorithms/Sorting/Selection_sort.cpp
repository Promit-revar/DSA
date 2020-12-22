#include<iostream>
#include<cstdio>
using namespace std;
void print(int *a,int n=10)
{
       for(int i=0;i<10;i++){
        cout<<a[i]<<" ";
    }
}
int * selection_sort(int *a,int n){
    if(n==0){
        //print(a);
        return a;
    }
    int temp;
    //cout<<n;
    for(int i=0;i<n-1;i++){
        //cout<<a[i];
        if(a[i]>a[i+1])
        {
            temp=a[i];
            a[i]=a[i+1];
            a[i+1]=temp;
        }
    }
    return selection_sort(a,n-1);
}

int main(){
    int a[10];
    for(int i=0;i<10;i++)
    scanf("%d",&a[i]);
    int * Sa=selection_sort(a,10);
    print(Sa);
    return 0;
}
