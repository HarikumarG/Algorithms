#include<bits/stdc++.h>
using namespace std;
void merge(int a[],int l,int m,int r)
{
	int b[m+r];
	int k=0;
	int i=l;
	int j=m+1;
	while(i<=m && j<=r)
	{
		if(a[i]<a[j])
		{
			b[k++]=a[i++];
		}
		else
		{
			b[k++]=a[j++];
		}
	}
	while(i<=m)
	{
		b[k++]=a[i++];
	}
	while(j<=r)
	{
		b[k++]=a[j++];
	}
    for(int o=l,m=0;o<=r;o++)
    {
    	a[o]=b[m];
    	m++;
    }
}
void mergesort(int a[],int l,int r)
{
	int m;
	if(l<r)
	{
		m=(l+r)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,r);
		merge(a,l,m,r);
	}
}
void printarray(int a[],int len)
{
	cout<<"\n";
	for(int i=0;i<len;i++)
	{
		cout<<a[i]<<" ";
	}
}
int main()
{
	int a[]={32,45,67,2,7};
	int len=sizeof(a)/sizeof(a[0]);
	printarray(a,len);
	mergesort(a,0,len-1);
	printarray(a,len);
	return 0;
}