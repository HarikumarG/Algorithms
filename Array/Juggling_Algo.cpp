#include<iostream>
using namespace std;
int gcd(int a,int b)
{
	if(b==0)
		return a;
	else
		gcd(b,a%b);
}
int rotatearray(int arr[],int d,int n)
{
	int i,j,k,temp;
	for(i=0;i<gcd(d,n);i++)
	{
		temp=arr[i];
		j=i;
		while(1)
		{
			k=j+d;
			if(k>=n)
				k=k-n;
			if(k==i)
				break;
			arr[j]=arr[k];
			j=k;
		}
		arr[j]=temp;
	}
	for(i=0;i<n;i++)
	{
		cout<<" "<<arr[i];
	}
}
int main()
{
	int a[20]={0,1,2,3,4,5,6,7,8,9,10,11},n=12,d=3;
	rotatearray(a,d,n);
	return 0;
}