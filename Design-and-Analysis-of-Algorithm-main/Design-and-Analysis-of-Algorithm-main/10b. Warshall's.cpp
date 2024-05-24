#include <iostream>
using namespace std;
#define MAX 10

int i,j,k,cost[MAX][MAX];

void createGraph(int cost[MAX][MAX], int n){
    cout << "Enter cost Matrix: \n";
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            cin >> cost[i][j];
        }
    }
}

void warshall(int cost[MAX][MAX], int n){
    for (k = 0; k < n; k++){
        for (i = 0; i < n; i++){
            for (j = 0; j < n; j++){
                cost[i][j] = cost[i][j] || (cost[i][k] && cost[k][j]);
            }
        }
    }
}
/*
void warshall(int adj[MAX][MAX], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                adj[j][k] = adj[j][k] || (adj[j][i] && adj[i][k]);
            }
        }
    }
}
*/

void printGraph(int cost[MAX][MAX], int n){
    cout << "After Applying Warshall's Transitive Closure:\n";
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            cout << cost[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    int n;
    cout << "Enter No of Vertices: ";
    cin >> n;
    createGraph(cost, n);
    warshall(cost, n);
    printGraph(cost, n);
}
