#include<bits/stdc++.h>
using namespace std;
int main()
{
	int v[2][3]  =  { {16, 18, 20}, {25, 26, 27} };
	int (*p)[3]= v;
	
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			cout<<*(*(p+i)+j)<<" ";
		}
		cout<<endl;
	}
	return 0;
}
