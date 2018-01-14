#include<bits/stdc++.h>
using namespace std;
int swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
int main()
{
	int a[7]={2,1,10,49,9,23,90},n=7;
	for(int i=0;i<n;i+=2)
	{
		//If current element is smaller than the previous 
		if(i>0 && a[i]<a[i-1])
			swap(&a[i],&a[i-1]);
		//If current element is smaller than the next
		if(i<n-1 && a[i]<a[i+1])
			swap(&a[i],&a[i+1]);
	}
	for(int i=0;i<n;i++)
		cout<<" "<<a[i];
	return 0;
}
