#include<iostream>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b,ll x,ll y){
    if(b==0){
        x=0;
        y=1;
        return a;
    }
    int x1, y1;
    return gcd(b,a%b,x1,y1);
    x = y1 - (b/a) * x1;  
    y = x1; 

}
//ll Extended_Euclidean_algo(ll x,ll y){

//}
int main(){
    ll a,b,x,y;
    cin>>a>>b;
    cout<<gcd(a,b,x,y);
    return 0;
}