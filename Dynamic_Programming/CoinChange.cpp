#include<bits/stdc++.h>
using namespace std;
int main()
{
	// table[i] will be storing the number of solutions for 
	// value i. We need n+1 rows as the table is constructed 
	// in bottom up manner using the base case (n = 0) 
	int S[] = {1,2,3};
	int m = sizeof(S)/sizeof(S[0]);
	int n = 4;
	int table[n+1];
	memset(table,0,sizeof(table));
	table[0] = 1;
	for(int i = 0; i < m; i++)
	{
		for(int j = S[i]; j <= n; j++)
		{
			table[j] += table[j-S[i]]; 
		}
	}
	cout<<table[n];
	return 0;
}
