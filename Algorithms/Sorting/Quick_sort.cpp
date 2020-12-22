#include<iostream>
#include<cstdio>
using namespace std;
int partition(int *a,int l,int r){
    int k=l,j=l;
    int pivot=a[l];
    for(int i=l+1;i<=r;i++){
        if(a[i]<=pivot){
            k++;
        }
        else{
            
        }
    }
}
void swapper(int *a,int l,int k){
    int temp=a[l];
    a[l]=a[k];
    a[k]=temp;
    
}
void quickSort(int *a,int l, int r){
    if(l>=r){
        return;
    }
    int k=rand()%10;
    swapper(a,l,k);
    int m=partition(a,l,r);
}
int main(){
    int n;
    int a[10];
    for(int i=0;i<10;i++){
        scanf("%d",&a[i]);
    }
    quickSort(a,0,9);
    return 0;
}