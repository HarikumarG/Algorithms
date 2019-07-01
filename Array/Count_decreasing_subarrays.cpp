#include <bits/stdc++.h> 
using namespace std; 
int countNonIncreasing(int arr[], int n) 
{ 
	// Initialize result 
	int cnt = 0; 

	// Initialize length of current non 
	// increasing subarray 
	int len = 1; 

	// Traverse through the array 
	for (int i = 0; i < n - 1; ++i) { 

		// If arr[i+1] is less than or equal to arr[i], 
		// then increment length 
		if (arr[i + 1] <= arr[i]) 
			len++; 

		// Else Update count and reset length 
		else { 
			cnt += (((len + 1) * len) / 2); 
			len = 1; 
		} 
	} 

	// If last length is more than 1 
	if (len > 1) 
		cnt += (((len + 1) * len) / 2); 

	return cnt; 
} 

// Driver code 
// {1},{4},{3},{4,3}
int main() 
{ 
	int arr[] = {1,4,3}; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	cout << countNonIncreasing(arr, n); 

	return 0; 
}

