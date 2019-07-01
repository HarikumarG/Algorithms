#include<bits/stdc++.h>
using namespace std;
void occurrence_element(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		int index=arr[i]%n;
		arr[index]=arr[index]+n;
	}
	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	int max=*max_element(arr, arr+n);
	cout<<"\n";
	for(i=0;i<n;i++)
	{
		if(arr[i]==max && (arr[i]/n)>1)
		{
			cout<<i;
		}
	}
}
int main()
{
	int arr[]={4,9,4,9,4,6};
	int n=sizeof(arr)/sizeof(arr[0]);
	occurrence_element(arr,n);
	return 0;
}