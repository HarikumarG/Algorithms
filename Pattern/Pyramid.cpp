#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n;
	int y = n-1;
	for(int i=0;i<n;i++)
	{
		k = y;
		while(k!=0)
		{
			cout<<" ";
			k--;
		}	
		for(int m=0;m<=i*2;m++)
			cout<<"*";
		cout<<"\n";
		y--;
	}
	return 0;
}
