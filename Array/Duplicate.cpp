#include<bits/stdc++.h>
using namespace std;
void duplicate(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		int index=arr[i]%n;
		arr[index]=arr[index]+n;
	}
	for(i=0;i<n;i++)
	{
		if((arr[i]/n)>1)
			cout<<i<<" ";
	}
}
int main()
{
	int arr[]={1,6,2,3,1,3,6,6,7,2};
	int n=sizeof(arr)/sizeof(arr[0]);
	duplicate(arr,n);
	return 0;
}