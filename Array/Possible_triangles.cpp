//https://www.geeksforgeeks.org/find-number-of-triangles-possible/
#include<bits/stdc++.h>
using namespace std;
int triangle(int a[],int n)
{
	sort(a,a+n);
	int i,k,j,count=0;
	for(i=0;i<n-2;i++)
	{
		k=i+2;
		for(j=i+1;j<n;j++)
		{
			while(k<n && a[i]+a[j]>a[k])
			{
				k++;
			}
			 // Total number of possible triangles that can 
            // be formed with the two fixed elements is
            //  k - j - 1.  The two fixed elements are arr[i]
            // and arr[j].  All elements between arr[j+1]/ to 
            // arr[k-1] can form a triangle with arr[i] and arr[j].
            // One is subtracted from k because k is incremented 
            // one extra in above while loop.
            // k will always be greater than j. If j becomes equal
            // to k, then above loop will increment k, because arr[k]
            //  + arr[i] is always greater than arr[k]
			count=count+k-j-1;
		}
	}
	cout<<count;
	return 0;
}
int main()
{
	int a[]={10,20,100,25,101,300,200};
	int n=sizeof(a)/sizeof(a[0]);
	triangle(a,n);
	return 0;
}