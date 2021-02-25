#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct Intervals{
    int start,end;
};
bool compare(Intervals i1,Intervals i2){
     return i1.start<i2.start;
}
int main(){
    int n;
    cin>>n;
    struct Intervals a[n];
    for(int i=0;i<n;i++){
        cin>>a[i].start>>a[i].end;
    }
    sort(a,a+n,compare);
    for(int i=0;i<n;i++)
    cout<<"[ "<<a[i].start<<" , "<<a[i].end<<" ]"<<endl;
return 0;
}
