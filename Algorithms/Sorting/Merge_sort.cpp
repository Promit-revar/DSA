#include<iostream>
#include<cstdio>
using namespace std;

void print(int * a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void Merge(int * a,int strt,int m,int end){    
    int i=strt,j=m+1,k=strt;
    int b[10];
    while(i<=m && j<=end){
       if(a[i]<=a[j]){
          b[k]=a[i];
          i++;
          k++;
       }
       else{
           b[k]=a[j];
           j++;
           k++;
       }
       //cout<<b[k]<<" ";
      
       
    }
    while(i<=m){
        b[k]=a[i];
        i++;
        k++;
        //cout<<b[k]<<" ";
    }
    while(j<=end){
        b[k]=a[j];
        j++;
        k++;
    }
    for(int i=strt;i<=end;i++){
        a[i]=b[i];
    }
    

}
void MergeSort(int *a,int i,int j){
    int m;
    if(i<j){
    m=(i+j)/2;
    MergeSort(a,i,m);
   MergeSort(a,m+1,j);
   Merge(a,i,m,j);
   }
}

int main(){
    int a[10];
    for( int i=0;i<10;i++){
        scanf("%d",&a[i]);
        
    }
    //print(a,10);
    MergeSort(a,0,9);
    print(a,10);
    return 0;
}