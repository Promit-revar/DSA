#include<iostream>
#include<stack>
#include<cstdio>
using namespace std;

int main(){
   int t;
   cin>>t;
   while(t--){
    int n;
    cin>>n;
    int a[n],cu[n]={0};
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    stack<int> st;
    //for(int i=n-1;i>=0;i--)
     //   cout<<a[i]<<" ";
    int j=n-1,u=0,nextMax=n;
    //cout<<st.top();
    while(j>=0){
    while(a[j]!=nextMax){
        st.push(a[j]);
        cu[a[j]-1]++;
        j--;




    }
    st.push(a[j]);
    j--;
    cu[nextMax-1]++;
     while(!st.empty()){
        //b[u]=st.top();
        cout<<st.top()<<" ";
        st.pop();
        //u++;
    }

    //cout<<st.top();
    while(cu[nextMax-1]!=0){
    nextMax--;
    //cout<<cu[nextMax-1]<<" "<<nextMax<< " "<<j<<endl;

    }

    cu[nextMax-1]=1;

    }
    //cout<<st.top()<<" "<<j<<endl;


    cout<<endl;
   }
return 0;
}
