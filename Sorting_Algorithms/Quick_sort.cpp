#include<iostream>
using namespace std;
int a[]={10, 7, 8, 9, 1, 5};
int partition(int low,int high)
{
	int pivot,i,j,temp;
	i=low;
	j=high;
	pivot=a[low];
	while(i<j)       //The major rule of quick sort is that the elements to the left of the pivot
	{				//should be lesser than the pivot and the elements to the right of the pivot
		while(a[i]<=pivot)  //should be greater than the pivot
			i++;
		while(a[j]>pivot)
			j--;
		if(i<j)         //swap if the low index value is lower than the high index value
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	a[low]=a[j];    //this is swapped since the low index value is higher than the high index value
	a[j]=pivot;     //Place the pivot value to a[j] 
	return j;      //now pivot is in correct position in the sorted array 
}

int quicksort(int low,int high)
{
	if(low<high)
	{
		int p=partition(low,high);   //This p gives the correct position of the partitioned index
		quicksort(low,p-1);			//at this a[p] value is at correct place in the sorted array
		//sorting left array
		quicksort(p+1,high);
		//sorting right array		
	}
	return 0;
}
int printarray(int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<" "<<a[i];
	}
	return 0;
}
int main()
{
	int n=sizeof(a)/sizeof(a[0]);
	quicksort(0,n-1);
	printarray(n);
	return 0;

}