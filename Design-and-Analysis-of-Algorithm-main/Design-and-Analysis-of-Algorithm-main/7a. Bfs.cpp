#include <iostream>
using namespace std;

void bfs(int cost[20][20],int source,int visited[20],int n){
    int queue[20], u, v;
    int f= 0;
    int r= -1;
    queue[++r]=source;
    while (f<=r){
        u=queue[f++];
        for (v=1;v<=n;v++){
            if (cost[u][v] == 1&&visited[v] == 0){
                queue[++r]=v;
                visited[v]=1;
            }
        }
    }
}

int main(){
    int n, cost[20][20], i, j, visited[20], source;
    cout <<"Enter the number of vertices:";
    cin >>n;
    cout <<"Enter the cost matrix (1 for edge & 0 for no-edge):\n";
    for(i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            cin >> cost[i][j];
    for(i=1;i<=n;i++)
        visited[i]=0;
    cout <<"Enter the source node:";
    cin >> source;
    visited[source] = 1;
    bfs(cost, source, visited, n);
    for (i=1;i<=n;i++){
        if (visited[i] != 0)
            cout<<"\nNode " << i << " is reachable";
        else
            cout <<"\n Node " << i << " is not reachable";
    }
}
