//Write a program to sort the elements in odd positions in descending order and elements in ascending order
//
//Eg 1: Input: 13,2 4,15,12,10,5
//        Output: 13,2,12,10,5,15,4
//Eg 2: Input: 1,2,3,4,5,6,7,8,9
//        Output: 9,2,7,4,5,6,3,8,1 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n=6;
	int even = n/2;
	int odd = n-even;
	int a[n] = {1,2,3,4,5,6};
	for(int i=0;i<n;i++)
	{
		if(i % 2 == 0)
		{
			int max1 = i;
			int k = i+2;
			for(int j=1;j<odd;j++)
			{
				if(a[max1] < a[k])
					max1 = k;
				k=k+2;
			} 
			swap(a[i],a[max1]);
			odd--;
		}
		else
		{
			int min1 = i;
			int k = i+2;
			for(int j=1;j<even;j++)
			{
				if(a[min1] > a[k])
					min1 = k;
				k=k+2;
			}
			swap(a[i],a[min1]);
			even--;
		}
	}
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	return 0;
}
