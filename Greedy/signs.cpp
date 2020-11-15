#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
bool compare(vector<ll> &a,vector<ll> &b){
    return a[0]<b[0];
}
int main(){
    ll a,b;
    int n;
    cin>>n;
    vector<vector<ll> > v;
    map <ll,int> mp;
    for(int i=0; i<n ; i++){
        cin>>a>>b;
        v.push_back({a,b,b-a});
        
    }
    sort(v.begin(),v.end(),compare);
    // for(int i=0;i<n;i++){
    //     cout<<"["<<v[i][0]<<","<<v[i][1]<<"] "<<v[i][2]<<endl;
    // }
    ll i=v[0][0];
        while(i<=v[n-1][1]){
             for(int j=0;j<n;j++){
                if(i>=v[j][0] && i<=v[j][1]){
                    mp[i]+=1;
                }
             }

        }


    
    return 0;
}