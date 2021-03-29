#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
using namespace std;
struct interval{
    int start,ending;

};
bool compare(interval a,interval b){
    return a.ending>b.ending;
}
int main(){
   int n;
   cin>>n;
   struct interval a[n];
   for(int i=0;i<n;i++){
    scanf("%d %d",&a[i].start,&a[i].ending);
   }
   sort(a,a+n,compare);
   /*for(interval i:a){
    cout<<i.start<<","<<i.ending<<endl;
   }*/
   stack<interval> st;
   st.push(a[0]);
   interval top;
   for(int i=1;i<n;i++)
   {
       top=st.top();
       if(a[i].ending>top.start){

         top.start=(a[i].start<top.start)?a[i].start:top.start;
         //cout<<top.start<<top.ending<<endl;
         st.pop();
         st.push(top);
       }else{
        st.push(a[i]);
       }
   }

   while(!st.empty()){
    cout<<st.top().start<<" , "<<st.top().ending<<endl;
    st.pop();

   }

return 0;
}
