#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n=7;
//	int a[n][n];
//	for(int line=0;line<n;line++)
//	{
//		for(int i=0;i<=line;i++)
//		{
//			if(line==i || i==0)
//			{
//				a[line][i]=1;
//			}
//			else
//			{
//				a[line][i]=a[line-1][i-1]+a[line-1][i];
//			}
//			cout<<a[line][i]<<" ";
//		}
//		cout<<"\n";
//	}
	for(int line = 1;line<=n;line++)
	{
		int c = 1;
		for(int i=1;i<=line;i++)
		{
			cout<<c<<" ";
			c = (c * (line - i))/i;
		}
		cout<<"\n";
	}
	return 0;
}
