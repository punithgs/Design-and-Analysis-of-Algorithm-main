#include<iostream>
using namespace std;
#define MAX 10

int board[MAX],i,j;

bool isSafe(int row,int col){
    for(i=0;i<row;i++){
        if (board[i] == col || (board[i] - col) == (i - row) || (board[i] - col) == (row - i)) {
            return false;
        }
    }
    return true;
}

void print(int n){
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) {
            if (board[i] == j)
                cout <<" Q ";
            else
                cout <<" - ";
        }
        cout <<"\n";
    }
    cout <<"\n";
}

void nqueen(int row,int n){
    if(row==n){
        print(n);
        return;
    }
    for(int col=0;col<n;col++){
        if(isSafe(row,col)){
           board[row]=col;
           nqueen(row+1,n);
        }
    }
}

int main(){
    int n;
    cout<<"Enter the No. of Queen's :";
    cin>>n;
    nqueen(0,n);
}
