#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n;
	int y = 1;
	
	for(int j=1;j<n*2;j++)
		cout<<"*";	
	cout<<"\n";	
		
	for(int i=n-1;i>0;i--)
	{
		k = y;
		while(k!=0)
		{
			cout<<" ";
			k--;
		}	
		for(int m=1;m<i*2;m++)
		{
			if(m==1 || m==i*2-1)
				cout<<"*";
			else
				cout<<" ";
		}
		cout<<"\n";
		y++;
	}
	return 0;
}
