#include<iostream>
using namespace std;
int swap(int *x,int *y)     //Iterative method
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
	return 0;
}
int bubble(int a[],int n)		
{
	for(int i=0;i<n-1;i++)		//since bubble sort should run n-1 times of passes should take place
	{
		for(int j=0;j<n-i-1;j++)   //n-i-1 since last i elements are already in place
		{
			if(a[j]>a[j+1])
			{
				swap(&a[j],&a[j+1]);
			}
		}
	}
}


//Recursive method 

int bubble_r(int a[],int n)
{
	if(n==1)     //Base condition
	{
		return 0;
	}
	for(int i=0;i<n-1;i++)
	{
		if(a[i]>a[i+1])
		{
			swap(&a[i],&a[i+1]);
		}
	}
	bubble_r(a,n-1);   //recursive call
}
int main()
{
	int a[]={64, 34, 25, 12, 22, 11, 90};
	int n=sizeof(a)/sizeof(a[0]);
	bubble(a,n);
	bubble_r(a,n);
	for(int k=0;k<n;k++)
	{
		cout<<" "<<a[k];
	}
	return 0;
}


