#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n;
	int y = 1;
	for(int i=n;i>0;i--)
	{
		for(int m=1;m<i*2;m++)
			cout<<"*";
		cout<<"\n";
		k = y;
		while(k!=0)
		{
			cout<<" ";
			k--;
		}	
		y++;
	}
	return 0;
}
