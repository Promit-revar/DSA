#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
void printdfs(int ** edges,int n,int sv,bool * visited){
    cout<<sv<<endl;
    visited[sv]=true;
    for(int i=0;i<n;i++){
            if(i==sv){
                continue;
            }
        if(edges[sv][i]==1){
                if(visited[i]){
                    continue;
                }
            printdfs(edges,n,i,visited);
        }
    }

}
void printbfs(int ** edges,int n,int sv,bool * visited,queue<int> &Q){

    if(Q.empty()){
        return;
    }
    for(int i=0;i<n;i++){
        if(edges[sv][i]==1 && !visited[i]){
            Q.push(i);

        }

    }
    if(!visited[sv]){
    cout<<sv<<" ";
    visited[sv]=true;
    }
    Q.pop();
    printbfs(edges,n,Q.front(),visited,Q);

}
void path(int **edges,int n,bool * visited,int st,int e,queue<int> &Q){
    if(st==e){
        cout<<e;
        return;
    }


    visited[st]=true;
    for(int i=0;i<n;i++){
        if(edges[st][i] && !visited[i]){
            Q.push(i);

        }
    }
    Q.pop();
    path(edges,n,visited,Q.front(),e,Q);
    cout<<" -> "<<st;



}
bool HasPath(int ** edges,int n,int st,int e,queue<int> &Q,bool *visited){

    if(st==e || edges[st][e])
        return true;
    for(int i=0;i<n;i++){

        if(edges[st][i]==1 && !visited[i]){
            Q.push(i);


        }

    }
    if(!visited[st]){

    visited[st]=true;
    }
    Q.pop();
    return HasPath(edges,n,Q.front(),e,Q,visited);

}
void settingVisited(bool * visited,int n){
    for(int i=0;i<n;i++){
        visited[i]=false;
    }

}
int main(){
    int n,e;
    cin>>n>>e;
    int** edges=new int*[n];

    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        //cout<<n<<e;
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }

    }
    int f,s;
    for(int i=0;i<e;i++){

        scanf("%d %d",&f,&s);
        edges[f][s]=1;
        edges[s][f]=1;
    }
    bool * visited=new bool[n];
    settingVisited(visited,n);
    printdfs(edges,n,0,visited);

    queue<int> Q;
    settingVisited(visited,n);
    for(int i=0;i<n;i++){
            if(!visited[i]){
            Q.push(i);
    printbfs(edges,n,i,visited,Q);
            }
    }
    while(!Q.empty()){
        Q.pop();
    }
    int k,st;
    cout<<endl;
    cout<<"ENTER the start and end vertex"<<endl;
    cin>>st>>k;
    Q.push(st);
    settingVisited(visited,n);
    if(HasPath(edges,n,st,k,Q,visited)){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    while(!Q.empty()){
        Q.pop();
    }
    Q.push(st);
    settingVisited(visited,n);

    path(edges,n,visited,st,k,Q);

return 0;
}

