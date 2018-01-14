#include<iostream>
using namespace std;
int gcd(int a,int b)
{
	if(b==0)
		return a;
	else
		gcd(b,a%b);
}
int leftrotatearray(int arr[],int d,int n)
{
	int i,j,k,temp;
	for(i=0;i<gcd(d,n);i++)     //The loop can run for GCD times since that is enough to rotate an array
	{
		temp=arr[i];            //Initialize the first array value to temp , to do the swapping process
		j=i;					
		while(1)
		{
			k=j+d;				//This is done to find the next dth element 
			if(k>=n)			//Base conditions
				k=k-n;
			if(k==i)
				break;
			arr[j]=arr[k];		//swapping process
			j=k;
		}
		arr[j]=temp;
	}
	for(i=0;i<n;i++)
	{
		cout<<" "<<arr[i];
	}
}
int rightrotatearray(int arr_r[],int d,int n)
{
	int i,j,k,temp,m,y;
	m=n-1;						//Since the value of n is higher than the array index number 
	i=m;						//if array size is 5 then array index value is 4 so that 1 is subracted 
	for(y=0;y<gcd(d,n);y++)		
	{
		temp=arr_r[i];			//assigning the value of last element to temp
		j=i;
		while(1)
		{
			k=j-d;				//This is done to find the next dth element in the reverse order 
			if(k<0)
				k=k+n;
			if(k==i)
				break;
			arr_r[j]=arr_r[k];
			j=k;
		}
		arr_r[j]=temp;
		i--;
	}
	cout<<"\n";
	for(i=0;i<n;i++)
	{
		cout<<" "<<arr_r[i];
	}

}
int main()
{
	int a[20]={0,1,2,3,4,5,6,7,8,9,10,11},n=12,d=3;
	int b[20]={0,1,2,3,4,5,6,7,8,9,10,11};
	leftrotatearray(a,d,n);
	rightrotatearray(b,d,n);
	return 0;
}