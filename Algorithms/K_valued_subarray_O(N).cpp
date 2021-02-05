#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int a[1000];
    map <int,int> mp;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int currsum=0,c=0;
    for(int i=0;i<n;i++){
        currsum+=a[i];
        mp[currsum]=i+1;
        //cout<<currsum<<" ";
        if(currsum==k){

            c++;
        }
        else if(mp[currsum-k]>0){
            c++;
        }

    }
    cout<<c;
return 0;
}
