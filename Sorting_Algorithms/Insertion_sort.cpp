#include<iostream>
using namespace std;
int insertionSort(int a[],int n)
{
	int i,j,key;
	for(i = 1; i < n; i++){
        key = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > key){
            a[j+1] = a[j];
            j-=1;
        }
        a[j+1] = key;
	}
	for(int k=0;k<n;k++)
	{
		cout<<" "<<a[k];
	}
}
int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, n);
     return 0;
}

