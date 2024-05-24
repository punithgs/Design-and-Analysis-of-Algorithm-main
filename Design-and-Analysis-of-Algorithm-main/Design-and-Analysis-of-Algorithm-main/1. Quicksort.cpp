#include<iostream>
#include<ctime>
#include<fstream>
using namespace std;

int partition(int a[],int l,int h){
    int pivot=a[l];
    int i=l,j=h,temp;
    
    while(i<j){
        do{
            i++;
        }while(a[i]<=pivot);
        do{
            j--;
        }while(a[j]>pivot);
        if(i<j){
           temp=a[i];
           a[i]=a[j];
           a[j]=temp;
        }
    }
    temp=a[l];
    a[l]=a[j];
    a[j]=temp;
    return j;
}

void quicksort(int a[],int l,int h){
    if(l<h){
        int j=partition(a,l,h);
        quicksort(a,l,j);
        quicksort(a,j+1,h);
    }
}

int main(){
int n, a[100000],i,j;

cout<<"Enter the Number of Elements to be sorted :";
cin>>n;
cout<<"The Random numbers are :"; 
for(i=0;i<n;i++){
    a[i]=rand()%100;
    cout<<a[i]<<" ";
}

clock_t start=clock();
quicksort(a,0,n);
clock_t end=clock();

cout<<"\nSorted Elements are :";
for(i=0;i<n;i++)
   cout<<a[i]<<" ";
double time=(double) (end-start)/CLOCKS_PER_SEC;
cout<<"\nTime taken for sorted "<<n<<" elements is :"<<time; 

ofstream file;
file.open("quicksort.txt", ofstream :: app);

for(i=10000;i<=100000;i+=2000){
        n=i;
        int a[n];
        for(j=0;j<n;j++)
           a[j]=rand()%100;
        clock_t start=clock();
        quicksort(a,0,n);
        clock_t end=clock();
        double t=(double) (end-start)/CLOCKS_PER_SEC;
        file<<n<<"\t"<<t<<"\n";
    }

file.close();
cout<<"\nTime to sort 10000 to 100000 (incrementing 2000 per iteration) element is added to the file quicksort.txt ";
return 0;
}
