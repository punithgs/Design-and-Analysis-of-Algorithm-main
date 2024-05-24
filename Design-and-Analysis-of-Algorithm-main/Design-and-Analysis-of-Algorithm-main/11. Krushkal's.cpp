#include<iostream>
using namespace std;
#define MAX 10

int parent[MAX],cost[MAX][MAX];

int find(int i){
    while(parent[i]>0)
        i=parent[i];
     return i;
}

void Union(int i,int j){
    parent[j]=i;
}

void krushkal(int cost[MAX][MAX],int n){
    int a=0,b=0,u=0,v=0;
    int i,j,min,mincost=0;
    int ne=1; //ne = no. of edges

    while(ne<n){
       
       for(i=1,min=999;i<=n;i++){
          for(j=1;j<=n;j++){
            if(cost[i][j]<min){
                min=cost[i][j];
                a=u=i;
                b=v=j;
            }
       }
    }
             u=find(u);
             v=find(v);
             if(u!=v){
                Union(u,v);
                cout << "\nEdge-"<<ne++<< " (" << a << "," << b << ") : " << min;
                mincost += min;
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
    krushkal(cost,n);
}
