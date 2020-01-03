//https://www.geeksforgeeks.org/split-array-two-equal-sum-subarrays/
#include<bits/stdc++.h>
using namespace std;
int find(int a[],int n)
{
	int l = 0,r = 0;
	for(int i = 0; i < n; i++)
		l += a[i];
	for(int i = n-1; i >= 0; i--)
	{
		r += a[i];
		l -= a[i];
		if(l == r)
			return i;
	}
	return -1;
}
int main()
{
	int a[] = {1,2,3,6};
	int n = sizeof(a)/sizeof(a[0]);
	int sp = find(a,n);
	if(sp == -1 || sp == n)
		cout<<"Not Possible";
	else
	{
		for(int i = 0; i < n; i++)
		{
			if(i == sp)
				cout<<endl;
			cout<<a[i]<<" ";
		}
	}
	return 0;
}
