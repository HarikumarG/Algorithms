#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n;
	int y = n/2;
	int z = 1;
	int g = (n/2)+1;
	for(int i=0;i<=n;i++)
	{
		if(i < n/2)
		{
			k = y;
			while(k!=0)
			{
				cout<<" ";
				k--;
			}
			for(int j=0;j<=i*2;j++)
			{
				cout<<"*";
			}
			y--;
			cout<<"\n";
		}
		else
		{
			for(int j=1;j<g*2;j++)
			{
				cout<<"*";
			}
			cout<<"\n";
			k = z;
			while(k!=0)
			{
				cout<<" ";
				k--;
			}
			g--;
			z++;
		}
	}
	
	return 0;
}
