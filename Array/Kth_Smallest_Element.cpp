// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to return the kth smallest 
// element from the array 
int kthSmallest(int* arr, int k, int n) 
{ 

	// Minimum and maximum element from the array 
	int low = *min_element(arr, arr + n); 
	int high = *max_element(arr, arr + n); 

	// Modified binary search 
	while (low <= high) { 

		int mid = low + (high - low) / 2; 

		// To store the count of elements from the array 
		// which are less than mid and 
		// the elements which are equal to mid 
		int countless = 0, countequal = 0; 
		for (int i = 0; i < n; ++i) { 
			if (arr[i] < mid) 
				++countless; 
			else if (arr[i] == mid) 
				++countequal; 
		} 

		// If mid is the kth smallest 
		if (countless < k 
			&& (countless + countequal) >= k) { 
			return mid; 
		} 

		// If the required element is less than mid 
		else if (countless >= k) { 
			high = mid - 1; 
		} 

		// If the required element is greater than mid 
		else if (countless < k 
				&& countless + countequal < k) { 
			low = mid + 1; 
		} 
	} 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 7, 10, 4, 3, 20, 15 }; 
	int n = sizeof(arr) / sizeof(int); 
	int k = 3; 

	cout << kthSmallest(arr, k, n); 

	return 0; 
} 

