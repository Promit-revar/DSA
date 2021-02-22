#include<iostream>

using namespace std;
#include<cstdio>
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int s;
        for(int i=0;i<n;i++){
            //cout<<arr[i]<<" ";

              s=arr[i];

              arr[i]=arr[arr[i]-1];
              arr[arr[i]-1]=s;


       //s=0;
        cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<" "<<arr[4];
        }
        //cout<<s;
        //cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<" "<<arr[4]<<" "<<arr[5];
  return 0;
}
