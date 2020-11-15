#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;

bool compare(float a,float b){
    return a>b;
}
int main(){
    int n;
    int x,y;
    map <float,int> mp;
    int  w;
    cin>>n>>w;
    int a[10000];
    for(int i=0;i<n;i++){
        cin>>x>>y;
        mp[x/y]=x;
        a[i]=x/y;
        
    }
    sort(&a[0],&a[n],compare);
    float c=0.0;

    for(int i=0;i<n;i++){
        if(mp[a[i]]/a[i]<=w){
            w-=mp[a[i]]/a[i];
            c+=mp[a[i]];
        }
        else{
            c+=a[i]*w;
            break;
        }
        


    }
    cout<<c;
    return 0;
}