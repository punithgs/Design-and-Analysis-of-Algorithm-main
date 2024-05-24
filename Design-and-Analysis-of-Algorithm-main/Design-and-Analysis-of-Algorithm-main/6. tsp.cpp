#include<iostream>
using namespace std;

int c[100][100],s,ver;
float optimum=999,sum;

int swap(int v[],int i,int j){
    int t;
    t=v[i];
    v[i]=v[j];
    v[j]=t;
}

int tsp (int v[],int n,int i ){
    int sum1,j,k;
    if(i==n){
        if(v[0]==s){
            for(j=0;j<n;j++)
                sum1=0;
            for(k=0;k<n-1;k++){
                sum1=sum1+ c[v[k]][v[k+1]];
            }
            sum1=sum1+c[v[n-1]][s];
            if(sum1 < optimum)
               optimum=sum1;
        }
    }
    else {
        for(j=i;j<n;j++){
           swap(v,i,j);
           tsp(v,n,i+1);
           swap(v,i,j);}
    }
}

void approx(int ver){
    int min, p, i, j, vis[20], from;
    for (i=1;i<=ver;i++)
        vis[i]=0;
    vis[s]=1;
    from=s;
    sum=0;
    for (j=1;j<ver;j++){
        min = 999;
        for (i=1;i<=ver;i++)
            if (vis[i] != 1 && c[from][i] < min && c[from][i] != 0)
            {
                min = c[from][i];
                p = i;
            }
        vis[p]= 1;
        from= p;
        sum=sum + min;
    }
    sum =sum+c[from][s];
}

int main(){
    int v[100],ver,n,i,j;
    cout <<"Enter No. of vertices :";
    cin>>ver;
    for(i=0;i<ver;i++)
    v[i]=i+1;
    cout<<"Enter the Cost matrix (999 for infinity)\n";
    for(i=1;i<=ver;i++)
      for(j=1;j<=ver;j++)
        cin>>c[i][j];
    cout<<"Enter Source :";
    cin>> s;
    tsp(v,ver,0);
    cout << "\nOptimum solution is = "<<optimum<<"\n"; 
    approx(ver);
    cout <<"Solution with Approximation Algorithm is = " << sum << "\n";
    cout <<"The approximation val is = " << ((sum / optimum) - 1) * 100 << "%";
}
