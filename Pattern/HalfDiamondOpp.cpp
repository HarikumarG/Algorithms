#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n;
	int y = n/2;
	int z = 1;
	for(int i=0;i<n;i++)
	{
		if(i <= n/2)
		{
			k=y;
			while(k!=0)
			{
				cout<<" ";
				k--;
			}
				
			for(int j=0;j<=i;j++)
				cout<<"*";
			y--;
		}
		else
		{
			k = z;
			while(k != 0)
			{
				cout<<" ";
				k--;
			}
			for(int k=i;k<n;k++)
				cout<<"*";
			z++;
		}
		cout<<"\n";
	}
	return 0;
}
