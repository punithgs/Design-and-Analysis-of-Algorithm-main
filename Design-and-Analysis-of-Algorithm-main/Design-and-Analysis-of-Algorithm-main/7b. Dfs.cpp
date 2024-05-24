#include<iostream>
using namespace std;

int visited[10],n,cost[10][10],count=0,i,j;

void dfs(int source){
    int i;
    visited[source]=1;
    count++;
    for(i=1;i<=n;i++){
        if((cost[source][i]==1)&&(visited[i]==0)){
            dfs(i);
        }
    }
}

int main(){
    int source;
    cout<<"Enter no. of vertices :";
    cin>>n;
    cout<<"Enter the cost matrix (1 for edge & 0 for no-edge)\n";
     for(i=1;i<=n;i++){
       for(j=1;j<=n;j++){
           cin>>cost[i][j];
       }
    }
    for(i=1;i<=n;i++)
        visited[i]=0;
    
    cout<<"Enter the Source Vertex :";
    cin>>source;

    dfs(source);
    
    if (count == n)
      cout <<"The graph is connected";
    else
      cout <<"The graph is not connected";
}
