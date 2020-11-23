#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
typedef long long ll;
bool compare(int a,int b){
    return a>b;
}
int main(){
    int n,k,c;
    vector<ll> v;
    map<int,vector<ll> > mp;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>k;
        v.push_back(k);
    }
    ll f;
    for(int j=9;j>0;j--){
        mp[j]={};
     }
    for(auto i :v){
        f=i;
        while(f>0){
            c=f%10;
            f/=10;
        }
        mp[c].push_back(i);
        //cout<<c<<" ";
     }
     for(int j=9;j>0;j--){
        sort(mp[j].begin(),mp[j].end(),compare);
     }
     for(int j=9;j>0;j--){
        if(!mp[j].empty()){
            cout<<mp[j][0];
            cout<<mp[j][1];
        }
     }

    return 0;
}