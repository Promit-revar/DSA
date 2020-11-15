#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
bool compare(vector<int>& a,vector<int>& b){
    if(a[1]==b[1]){
        return a[0]%10>b[0]%10;
    }
    return a[1]>=b[1];
}

int main(){
    int n,c,d,y;
    cin>>n;
    vector<vector<int> > v;
    for(int i=0;i<n;i++){
        scanf("%d",&d);
        v.push_back({d});
    }
    for(int i=0;i<n;i++){
        
        y=v[i][0];
        while(y>0){
            c=y%10;
            y/=10;
        }
        v[i].push_back(c);
        //cout<<v[i][0]<<" "<<v[i][1]<<endl;

        
    }
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<n;i++){
        cout<<v[i][0];
    }
    return 0;
}