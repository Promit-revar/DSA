#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int n,k;
    int a[1000];
    cin>>n>>k;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int sum=0,c=0;
    
    for(int i=0;i<n;i++){
        sum=0;
        for(int j=i;j<n;j++)
        {
            sum+=a[j];
            if(sum==k){
                c+=1;
            }

        }
    }
    cout<<c;
    return 0;
}