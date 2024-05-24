#include<iostream>
using namespace std;
#define MAX 10

int cost[MAX][MAX],n,indegree[10],i,j;

void find_indegree(){
    int sum;
    for(i=1;i<=n;i++){
        sum=0;
        for(j=1;j<=n;j++)
            sum+=cost[j][i];
        
        indegree[i]=sum;
    }
}

void topo_sort(){
    int u,v,topo[10],stack[10],top=-1,k=0;
    find_indegree();
    for(i=1;i<=n;i++){
        if(indegree[i]==0){
            stack[++top]=i;
        }
    }
    while(top!=-1){
        u=stack[top--];
        topo[++k]=u;
        for(v=1;v<=n;v++){
            if(cost[u][v]==1){
                indegree[v]--;
                if(indegree[v]==0){
                    stack[++top]=v;
                }
            }
        }
    }
    cout<<"Topological Ordering :\n";
    for(i=1;i<=n;i++){
        cout<<topo[i]<<"\t";
    }
}

int main(){
    cout<<"Enter the no. of nodes :";
    cin>>n;
    cout<<"Enter the cost matrix (1 for edge & 0 for no-edge)\n";
     for(i=1;i<=n;i++){
       for(j=1;j<=n;j++){
           cin>>cost[i][j];
       }
    }
    topo_sort();
}
