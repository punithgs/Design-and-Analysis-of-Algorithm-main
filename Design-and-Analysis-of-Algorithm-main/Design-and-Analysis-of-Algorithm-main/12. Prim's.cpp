#include<iostream>
using namespace std;
#define MAX 10

int cost[MAX][MAX];

void prims(int cost[MAX][MAX],int n){
    int a=0,b=0,u=0,v=0;
    int i,j,min,mincost=0;
    int ne=1;  //ne = no. of edges
    int visited[10]={0};
    visited[1]=1;

    while(ne<n){
       
       for(i=1,min=999;i<=n;i++){
          for(j=1;j<=n;j++){
               if(cost[i][j]<min){
                  if(visited[i]!=0){
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                  }
               }
          }
       }
    if(visited[u]==0 || visited[v]==0){
            cout << "\nEdge-" <<ne++<< " (" << a << "," << b << ") : " << min;
            mincost += min;
            visited[b]=1;
       }
       cost[a][b]=cost[b][a]=999;
   }
   cout<<"\nMinimum cost :"<<mincost;
}

int main(){
    int n,i,j;
    cout<<"Enter the no. of vertices :";
    cin>>n;
    cout<<"Enter the cost matrix (999 for no-edge and self loops)\n";
    for(i=1;i<=n;i++){
       for(j=1;j<=n;j++){
           cin>>cost[i][j];
       }
    }
    prims(cost,n);
}
