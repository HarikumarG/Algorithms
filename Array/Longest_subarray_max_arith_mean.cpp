// C++ implementation of the above approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to find maximum distance 
// between unequal elements 
int longestSubarray(int arr[], int n) 
{ 

	// Calculate maxMean 
	int maxMean = 0; 
	for (int i = 1; i < n; i++) 
		maxMean = max(maxMean, 
					(arr[i] + arr[i - 1]) / 2); 

	// Iterate over array and calculate largest subarray 
	// with all elements greater or equal to maxMean 
	int ans = 0; 
	int subarrayLength = 0; 
	for (int i = 0; i < n; i++) 
		if (arr[i] >= maxMean) 
			ans = max(ans, ++subarrayLength); 
		else
			subarrayLength = 0; 

	return ans; 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 4, 3, 3, 2, 1, 4 }; 

	int n = sizeof(arr) / sizeof(arr[0]); 

	cout << longestSubarray(arr, n); 

	return 0; 
} 

