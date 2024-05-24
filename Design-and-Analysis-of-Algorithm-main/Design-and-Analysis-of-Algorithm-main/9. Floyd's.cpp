#include <iostream>
using namespace std;
#define MAX 10
#define INF 999

int i,j,k,cost[MAX][MAX];

#define min(x,y) (((x)>(y) ? y: x))

/*
int min(int a, int b) {
    return (a < b) ? a : b;
}
*/

void create(int cost[MAX][MAX], int n){
    cout << "Enter cost Matrix (999 for infinity)\n";
    for ( i = 0; i < n; i++){
        for ( j = 0; j < n; j++){
            cin >> cost[i][j];
        }
    }
}

void floyd(int cost[MAX][MAX], int n){
    for ( k = 0; k < n; k++){
        for ( i = 0; i < n; i++){
            for ( j = 0; j < n; j++){
                cost[i][j] = min(cost[i][j], (cost[i][k] + cost[k][j]));
            }
        }
    }
}
/*
void floyd(int cost[MAX][MAX], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                cost[j][k] = min(cost[j][k], cost[j][i] + cost[i][k]);
            }
        }
    }
}
*/

void print(int cost[MAX][MAX], int n){
    cout <<"After applying Floyd's Algorithm :\n";
    for (i = 0; i < n; i++){
        for ( j = 0; j < n; j++){
            if (cost[i][j] == INF)
                cout << "INF ";
            else
                cout << cost[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    int n;
    cout << "Enter No of Vertices: ";
    cin >> n;
    create(cost, n);
    floyd(cost, n);
    print(cost, n);
}
