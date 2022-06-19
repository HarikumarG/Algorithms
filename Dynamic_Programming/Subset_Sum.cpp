#include <iostream>
using namespace std;

bool isSubsetSumRecur(int set[], int n, int sum, int ind)
{
	if(sum == 0)
		return true;
	if(sum < 0)
		return false;
	if(ind >= n)
		return false;

	for(int i = ind; i < n; i++) {
		if(isSubsetSumRecur(set, n, sum-set[i], i+1))
			return true;
	}
	return false;
}

bool isSubsetSumDp(int set[], int n, int sum) {
	bool dp[n+1][sum+1];

	for(int i = 0; i <= n; i++)
		dp[i][0] = true;
	for(int j = 0; j <= sum; j++)
		dp[0][j] = false;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= sum; j++) {
			if(j < set[i-1]) {
				dp[i][j] = dp[i-1][j];
			} else {
				dp[i][j] = dp[i-1][j-set[i-1]];
			}
		}
	}
	return dp[n][sum];
}

int main()
{
	int set[] = {3,34,4,12,5,2};
	int sum = 13;
	int n = sizeof(set)/sizeof(set[0]);
	if(isSubsetSumRecur(set, n, sum, 0) && isSubsetSumDp(set, n, sum))
		cout<<"Found a subset with their sum equal to the given sum"<<endl;
	else
		cout<<"No subset with their sum equal to the given sum"<<endl;
	return 0;
}
