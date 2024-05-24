#include<iostream>
#include<ctime>
#include<fstream>
using namespace std;
 
void merge(int a[], int low, int high, int mid){
	int i, j, k, temp[high-low+1];
	i = low;
	k = 0;
	j = mid + 1;
	while (i <= mid && j <= high){
		if (a[i] < a[j]){
			temp[k] = a[i];
			k++;
			i++;
		}
		else{
			temp[k] = a[j];
			k++;
			j++;
		}
	}
	while (i <= mid){
		temp[k] = a[i];
		k++;
		i++;
	}
	while (j <= high){
		temp[k] = a[j];
		k++;
		j++;
	}
	for (i = low; i <= high; i++){
		a[i] = temp[i-low];
	}
}

void mergesort(int a[], int low, int high){
	int mid;
	if (low < high){
		mid=(low+high)/2;
		mergesort(a, low, mid);
		mergesort(a, mid+1, high);
		merge(a, low, high, mid);
	}
}
 
int main()
{
	int n, i,a[100000],j;
	cout<<"Enter the Number of Element to be sorted : ";
	cin>>n;
    cout<<"The Random numbers are :"; 
    for(i=0;i<n;i++){
    a[i]=rand()%100;
    cout<<a[i]<<" ";
}

 clock_t start=clock();
 mergesort(a, 0, n-1);
 clock_t end=clock();

cout<<"\nSorted Element are : ";
for (i = 0; i < n; i++)
    cout<<" "<<a[i];
double time=(double) (end-start)/CLOCKS_PER_SEC;
cout<<"\nTime taken for sorted "<<n<<" elements is :"<<time;   

ofstream file;
file.open("mergesort.txt", ofstream :: app);

for(i=10000;i<=100000;i+=2000){
        n=i;
        int a[n];
		for(j=0;j<n;j++)
           a[j]=rand()%100;
        clock_t start=clock();
        mergesort(a,0,n-1);
        clock_t end=clock();
        double t=(double) (end-start)/CLOCKS_PER_SEC;
        file<<n<<"\t"<<t<<"\n";
    }

   file.close();
   cout<<"\nTime to sort 10000 to 100000 (incrementing 2000 per iteration) element is added to the file mergesort.txt ";
   return 0;
}
