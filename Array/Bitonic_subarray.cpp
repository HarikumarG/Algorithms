#include<bits/stdc++.h>
using namespace std;
int bitonic(int a[],int n)
{
	int max,i;
	int inc[n];
	int dec[n];
	inc[0]=1;   //initializing first element
	dec[n-1]=1; //initializing last element
	for(i=1;i<n;i++) 
	{
		if(a[i]>=a[i-1])  //Check that it is in increasing order or not from left to right 
		{
			inc[i]=inc[i-1]+1;  //if yes then assign 1 to the corresponding index and 
		}						//for second time increment the array value by one and so on
		else
		{ 
			inc[i]=1;			//else just assign 1
		}
	}
	for(i=n-2;i>=0;i--)
	{
		if(a[i]>=a[i+1])    //check that it is in decreasing order or not from right to left
		{
			dec[i]=dec[i+1]+1; //if yes then assign 1 to the corresponding index and
		}						//for second time increment the array value by one and so on
		else
		{
			dec[i]=1;           //else just assign 1
		}
	}
	max=inc[0]+dec[0]-1;   //initialise max value by adding both the array values of first index
	for(i=1;i<n;i++)
	{
		if(inc[i]+dec[i]-1>max)//check and find the max value for the corresponding index values 
		{						//eg if inc{1,1,2,3,1} and dec{1,2,3,1,1} then inc[0]+dec[0]=max
			max=inc[i]+dec[i]-1;	//the check max<inc[1]+dec[1]  if true then assign that
		}							//value to the max 
	}
	return max;			
}
int main()
{
	int arr[] = {12, 4, 78, 90, 45, 23};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<bitonic(arr,n);
    return 0;
}
