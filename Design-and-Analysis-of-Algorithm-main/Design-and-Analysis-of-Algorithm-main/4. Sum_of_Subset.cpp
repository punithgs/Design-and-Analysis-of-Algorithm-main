#include <iostream>
using namespace std;

int s[10], d, n, set[10], count = 0;
int flag = 0,i,j;

void display(int count){
    cout << "{";
    for (i=0;i<count;i++)
        cout << " " << set[i] << " ";
    cout << "}\n";
}

void subset(int sum, int i){
    if (sum == d){
        flag = 1;
        display(count);
        return;
    }
    if (sum > d || i >= n)
        return;
    else{
        set[count] = s[i];
        count++;
        subset(sum + s[i], i + 1);
        count--;
        subset(sum, i + 1);
    }
}

int main()
{
    cout << "Enter the No. of elements: ";
    cin >> n;
    cout << "Enter the Values: ";
    for (i=0;i<n;i++)
        cin >> s[i];
    cout << "Enter the sum: ";
    cin >> d;
    cout << "Solution :\n";
    subset(0, 0);
    if (flag == 0)
        cout << "There is no solution.\n";
}
