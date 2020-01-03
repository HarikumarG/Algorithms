#include<bits/stdc++.h>
using namespace std;
bool isSubsetsum(int set[],int n,int sum)
{
	bool subset[n+1][sum+1];
	// If sum is 0, then answer is true
	for(int i = 0; i <= n; i++)
		subset[i][0] = true;
	// If sum is not 0 and set is empty, then answer is false
	for(int i = 1; i <= sum; i++)
	{
		subset[0][i] = false;
	}
	//Fill the table in bottom up manner
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= sum; j++)
		{
			if(j < set[i-1])
				subset[i][j] = subset[i-1][j];
			else if(j >= set[i-1])
				subset[i][j] = subset[i-1][j] || subset[i-1][j-set[i-1]];
		}
	}
	//For reference of the table
	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= sum; j++)
		{
			cout<<subset[i][j]<<" ";
		}
		cout<<endl;
	}
	return subset[n][sum];
}
int main()
{
	int set[] = {3,34,4,12,5,2};
	int sum = 9;
	int n = sizeof(set)/sizeof(set[0]);
	if(isSubsetsum(set,n,sum))
		cout<<"Found a subset with their sum equal to the given sum";
	else
		cout<<"No subset with their sum equal to the given sum";
	return 0;
}
