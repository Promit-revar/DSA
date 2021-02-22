#include<iostream>
#include<cstdio>
using namespace std;
#include<queue>
void sortKArray(int a[] ,int k,int n){
    priority_queue<int> pq;
    for(int i=0;i<k;i++){
        pq.push(a[i]);
    }
    int j=0;
    for(int i=k;i<n;i++){
        a[j]=pq.top();
        pq.pop();
        pq.push(a[i]);
        j++;
    }
    while(!pq.empty()){
        a[j]=pq.top();
        pq.pop();
        j++;
    }

}
void kSmallest(int *a,int n,int k){
    priority_queue<int> pq;
    for(int i=0;i<k;i++){
        pq.push(a[i]);
    }
    for(int i=k;i<n;i++){
        if(a[i]<pq.top()){
            pq.pop();
            pq.push(a[i]);
        }
    }
    int ans[k]={0};
    int i=0;
    while(!pq.empty()){
        ans[i]=pq.top();
        pq.pop();
        i++;
    }
    for(int i:ans){
        cout<<i<<" ";
    }

}
int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    kSmallest(a,n,k);
    sortKArray(a,k,n);

    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

return 0;
}
