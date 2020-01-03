// C++ code for Max 
// Water Container 
#include<iostream> 
using namespace std; 

int maxArea(int A[], int len) 
{ 
	int l = 0; 
	int r = len -1; 
	int area = 0; 
	
	while (l < r) 
	{ 
		// Calculating the max area 
		area = max(area, min(A[l], 
						A[r]) * (r - l)); 
						
			if (A[l] < A[r]) 
				l += 1; 
				
			else
				r -= 1; 
	} 
	return area; 
} 

// Driver code 
int main() 
{ 
	int a[] = {1, 5, 4, 3}; 
	int b[] = {3, 1, 2, 4, 5}; 
	
	int len1 = sizeof(a) / sizeof(a[0]); 
	cout << maxArea(a, len1); 
	
	int len2 = sizeof(b) / sizeof(b[0]); 
	cout << endl << maxArea(b, len2); 
} 

// This code is contributed by Smitha Dinesh Semwal 

