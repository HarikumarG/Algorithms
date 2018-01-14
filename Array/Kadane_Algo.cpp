//Maximum sum of an contiguous sub-array
#include<iostream>
using namespace std;
int maxsubsum(int a[],int n)
{
	int max_ending_here=0,max_ending_so_far=-999;
	for(int i=0;i<n;i++)
	{
		max_ending_here=max_ending_here+a[i];  //Adding the array elements contiguously 
		if(max_ending_so_far < max_ending_here)  //incase of any max value occurs in sum then that
		{										//assigns to the far value
			max_ending_so_far=max_ending_here;
		}
		if(max_ending_here<0)               //sum cannot be less than 0 
		{		
			max_ending_here=0;				//so incase of less than 0 it initializes 0
		}
	}
	return max_ending_so_far;
}
int main()
{
	int a[]={-2, -3, 4, -1, -2, 1, 5, -3};
	int n=sizeof(a)/sizeof(a[0]);
	int maxsum=maxsubsum(a,n);
	cout<<"Maximum sum :"<<maxsum;
	return 0;
}