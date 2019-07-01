//Given an array after removing any one element from an array the remaining sum of 
//consecutive elements should be the minimum value of all 
#include<bits/stdc++.h>
using namespace std;
#define n 4
int solve(int a[])
{
	int i,j,max=INT_MIN;
	int st,fi,x,y,min;
	for(i=0;i<n-1;i++)
	{
		j=i+1;
		int diff=abs(a[i]-a[j]);
		if(diff > max){
			max=diff;
			st=i;
			fi=j;
		}
	}
	if(st==0)
	{
		x=abs(a[st]-a[fi+1]);
		y=abs(a[fi]-a[fi+1]);
		if(x > y)			
			return a[st];
		else
			return a[fi];
	}
	else if(fi==n-1)
	{
		x=abs(a[st-1]-a[fi]);
		y=abs(a[st-1]-a[st]);
		if(x > y)
			return a[fi];
		else
			return a[st];
	}
	else
	{
		x=abs(a[st-1]-a[fi]);
		y=abs(a[st]-a[fi+1]);
		if(x<y)
		{
			if(x<=max)
				min=x;
			else
				min=max;
		}
		else
		{
			if(y<=max)
				min=y;
			else
				min=max;
		}
	}
	if(min==y)
		return a[fi];
	else if(min==x)
		return a[st];
	else
	{
		if(x>=y)
			return a[st-1];
		else
			return a[fi+1];
	}
}
int main()
{
	int a[n]={1,6,12,17};
	int ans=solve(a);
	cout<<ans;
	return 0;
}