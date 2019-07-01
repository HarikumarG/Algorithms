#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n=7;
	int a[n][n];
	for(int line=0;line<n;line++)
	{
		for(int i=0;i<=line;i++)
		{
			if(line==i || i==0)
			{
				a[line][i]=1;
			}
			else
			{
				a[line][i]=a[line-1][i-1]+a[line-1][i];
			}
			cout<<a[line][i]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}