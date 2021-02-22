#include<iostream>
#include<cstdio>
using namespace std;
void heapify(int *a,int n){
    int rtinx=0;
    int pin=0;
    int temp=0;
    for(int i=0;i<n;i++){
            rtinx=i;
            if(rtinx==0){
                pin=0;
            }
            else if(rtinx%2==0){
                pin=(rtinx-2)/2;
            }
            else{
                pin=(rtinx-1)/2;
            }
        while(a[rtinx]<a[pin]){
            temp=a[rtinx];
            a[rtinx]=a[pin];
            a[pin]=temp;
            rtinx=pin;
            if(rtinx%2==0){
                pin=(rtinx-2)/2;
            }
            else{
                pin=(rtinx-1)/2;
            }
        }
    }



}
void heapSort(int * a,int n){
    int index=0;
    int temp,ut=a[0];
    for(int i=n-1;i>=0;i--){
        temp=a[i];
        a[i]=a[0];
        a[0]=temp;
        index=0;
        if(i<2){
            return;
        }
        while(a[index]>a[2*index+1] || a[index]>a[2*index+2]){

            if(a[2*index+2]>a[2*index+1]){
                temp=a[2*index+1];
                a[2*index+1]=a[index];
                a[index]=temp;

            }
            else{
                temp=a[2*index+2];
                a[2*index+2]=a[index];
                a[index]=temp;

            }
        }
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    heapify(a,n);
    heapSort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
