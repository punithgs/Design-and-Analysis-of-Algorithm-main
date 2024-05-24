#include<iostream>
using namespace std;
#define MAX 10

int knap[MAX][MAX];

int max(int a,int b){
   return (a>b) ? a : b ;
}

int knapsack(int items, int capacity, int profit[], int weight[]){
    int i, j;
    for (i=1; i<=items; i++){
        for (j=1; j <=capacity; j++){
            if (j < weight[i]) {
                knap[i][j] = knap[i - 1][j];
            } else {
                knap[i][j] = max(knap[i - 1][j], profit[i] + knap[i - 1][j - weight[i]]);
            }
        }
    }
   return knap[items][capacity];
}
/*
int knapsack(int items, int capacity, int profit[], int weight[]){
    int i,j;
     for (i = 1; i <= items; i++){
        for (j = 1; j <= capacity; j++){
            knap[i][j] = (j < weight[i]) ? knap[i - 1][j] : max(knap[i - 1][j], profit[i] + knap[i - 1][j - weight[i]]);
        }
   }
    return knap[items][capacity];
}
*/

int main(){
    int i,j,n,items,capacity,profit[MAX],weight[MAX],optimum_val;
    cout << "Enter No. of objects: ";
    cin >>items;
    cout << "Enter the Weights: ";
    for (i=1;i<=items;i++)
        cin>>weight[i];
    cout << "Enter the Profits: ";
    for (i=1;i<=items;i++)
        cin>>profit[i];
    cout << "Enter the Knapsack Capacity: ";
    cin >> capacity;
    optimum_val=knapsack(items,capacity,profit,weight);
    cout<<"Profit Table\n";
    for(i=0;i<=items;i++){
      for(j=0;j<=capacity;j++){
        cout<<knap[i][j]<<"\t";
      }
      cout<<"\n";
    }
    cout<<"\nThe Maximum Profit is : "<<optimum_val;
}

/* 
#include <iostream>
using namespace std;

int p[50], w[50], n;

int knapsack(int i, int m)
{
    if (i == n)
        return (w[n] > m) ? 0 : p[n];
    if (w[i] > m)
        return knapsack(i + 1, m);
    return max(knapsack(i + 1, m), knapsack(i + 1, m - w[i]) + p[i]);
}
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main()
{
    int m, i, optsoln;
    cout << "Enter no. of objects: ";
    cin >> n;
    cout << "\nEnter the weights:\n";
    for (i = 1; i <= n; i++)
        cin >> w[i];
    cout << "\nEnter the profits:\n";
    for (i = 1; i <= n; i++)
        cin >> p[i];
    cout << "\nEnter the knapsack capacity:";
    cin >> m;
    optsoln = knapsack(1, m);
    cout << "\nThe optimal soluntion is:" << optsoln;
}
*/
