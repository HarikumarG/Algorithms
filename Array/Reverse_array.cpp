#include<iostream>
using namespace std;
//Recursive method 
int reverse(int arr[],int start,int end)
{
	int temp;
	if(start>=end)   //base condition 
		return 0;
	temp=arr[start];
	arr[start]=arr[end];
	arr[end]=temp;
	reverse(arr,start+1,end-1);
}
int main()
{
	int  a[5]={1,2,3,4,5};
	int start=0,n=5,end;
	end=n-1;
	reverse(a,start,end);
	for(int i=0;i<n;i++)
		cout<<" "<<a[i];
	return 0;
}