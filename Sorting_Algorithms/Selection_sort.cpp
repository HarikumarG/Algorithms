#include<iostream>
using namespace std;
int swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
	return 0;
}
int selection(int a[],int n)
{
	int i,j,min;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
			{
				min=j;
			}
		}
		swap(&a[min],&a[i]);
	}
}
int main()
{
	int a[]={64, 34, 25, 12, 22, 11, 90};
	int n=sizeof(a)/sizeof(a[0]);
	selection(a,n);
	for(int k=0;k<n;k++)
	{
		cout<<" "<<a[k];
	}
	return 0;
}
