#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[]={10,5,15};
	int b[]={20,3,2,12};
	int i=0,j=0,k=0;
	int n=sizeof(a)/sizeof(a[0]);
	int m=sizeof(b)/sizeof(b[0]);
	int r[n+m];

	while(i<n)
	{
		r[k]=a[i];
		i++;
		k++;
	}

	while(j<m)
	{
		r[k]=b[j];
		k++;
		j++;
	}

	
	sort(r,r+n+m);
	for(int y=0;y<n+m;y++)
	{
		cout<<"\t"<<r[y];
	}
	return 0;
}