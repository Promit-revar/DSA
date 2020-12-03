#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<string>
#include<cstdio>
using namespace std;
typedef long long ll;
bool compare(int a,int b){
    return a>b;
}
int main(){
    int n,k,c;
    int a[100];
    vector<vector<int>> v;
    vector<int> b;
    cin>>n;
    string s="0123456789";
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        
        while(a[i]>0){
            c=a[i]%10;
            a[i]/=10;
            b.insert(b.begin(),c);
        }
        // for(auto i :b){
        //     cout<<i;
        // }
        v.push_back(b);
        b.clear();
    }


    return 0;
}