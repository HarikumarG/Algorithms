#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		if(i <= n/2)
		{
			for(int j=0;j<=i;j++)
				cout<<"*";
		}
		else
		{
			for(int k=i;k<n;k++)
				cout<<"*";
		}
		cout<<"\n";
	}
	return 0;
}
