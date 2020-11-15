#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
// int naive(vector<int>& v){
    
// }
int main(){
    ll n;
    //cin>>n;
    vector<int> v;
    int yrs;
    while(true){
        ll n=rand()%100;
        for(int i=0;i<n;i++){
        //cin>>yrs;
        yrs=rand()%10;
        v.push_back(yrs);
    }
    
    sort(v.begin(),v.end());
    ll i=0,j=1,c=0;
    while(i<n){
        j=i+1;
        while(j<n && v[j]-v[i]<=1 ){
            j++;

        }
        i+=j;
        c++;
    }
    cout<<c<<endl;
    }
    return 0;
}