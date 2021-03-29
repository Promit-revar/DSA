#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix.at(0).size();
        vector<vector<int>> t;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    t.push_back({i,j});

                }
            }
        }

            for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<t.size();k++){
                    if(i==t[k][0] || j==t[k][1]){
                        matrix[i][j]=0;
                        break;
                    }
                }
            }
        }



    }
};
/*class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // int* row = new int[matrix.size()];
        // int* col = new int[matrix[0].size()];
        vector<int> row(matrix.size(),0);
        vector<int> col(matrix[0].size(),0);

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(row[i]==1 || col[j]==1){
                    matrix[i][j]=0;
                }
            }
        }


    }
};*/
int main(){
    Solution *obj=new Solution();
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix;
    vector<int> v;
    int t;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&t);
            v.push_back(t);
        }
        matrix.push_back(v);
    }
    obj->setZeroes(matrix);
    for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<matrix[i][j]<<" ";

                }

            cout<<endl;
        }

return 0;
}
