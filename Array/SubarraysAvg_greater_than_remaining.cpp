#include<bits/stdc++.h>
using namespace std;
int countSubarrays(int arr[],int n)
{
	int pre[n+1] = { 0 };
	int count = 0;
	for(int i=1;i<=n;i++)
		pre[i] = pre[i-1] + arr[i-1];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int sum1 = pre[j] - pre[i-1];
			int sum2 = pre[n] - sum1;
			int count1 = j-i+1;
			int count2 = ((n - count1) == 0) ? 1 : (n - count1);
			int includ = sum1/count1;
			int exclud = sum2/count2;
			if(includ > exclud)
				count++; 
		}
	}
	return count;
}
int main()
{
	int arr[] = { 6, 3, 5 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << countSubarrays(arr, n); 
    return 0; 
}
