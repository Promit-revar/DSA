#include<iostream>
#include<cstdio>
using namespace std;
class Solution {
public:
    void merge(int* nums1, int m, int * nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while(i>=0 && j>=0)
        {
            if(nums1[i]>nums2[j])
                nums1[k--]=nums1[i--];
            else
                nums1[k--]=nums2[j--];
        }
        while(j>=0)
            nums1[k--]=nums2[j--];
    }
};
int main(){
Solution sol;
int n,m;
cin>>n>>m;

int a[m+n]={0};
int b[n];
for(int i=0;i<m;i++){
    scanf("%d",&a[i]);
}
for(int i=0;i<n;i++){
    scanf("%d",&b[i]);
}
sol.merge(a,m,b,n);
 return 0;
}
/*
input type:
[-1,0,0,3,3,3,0,0,0]
6
[1,2,2]
3
*/
