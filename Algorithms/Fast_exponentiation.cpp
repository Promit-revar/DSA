#include<iostream>
using namespace std;
typedef long long ll;
ll expo(int a,int b){
   
   if (b==1)
        return a;
    if (b==2)
        return a*a;

    if (b%2==0){
            return expo(expo(a,b/2),2);
    }
    else{
        return a*expo(expo(a,(b-1)/2),2);
    }
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<expo(a,b);
    
    return 0;
}
/*
To set the ith bit:
Let us consider a value x. We perform x |=x<<i for setting a bit. To put it simply, we left shift x by i bits, and perform the bitwise operation, as it ideally does not change values

To unset the ith bit:
We use x&=~(x<<i).

To toggle a bit:
For this, we use the operation x^=x<<i.
*/