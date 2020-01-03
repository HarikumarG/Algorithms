// C++ program for printing 
// the rectangular pattern 
#include<bits/stdc++.h> 
using namespace std; 

// Function to print the pattern 
void printPattern(int n) 
{ 
	int arraySize = n * 2 - 1; 
	int result[arraySize][arraySize]; 
		
	// Fill the values 
	for(int i = 0; i < arraySize; i++) 
	{ 
		for(int j = 0; j < arraySize; j++) 
		{ 
			if(abs(i - arraySize / 2) > abs(j - arraySize / 2)) 
				result[i][j] = abs(i - arraySize / 2) + 1; 
			else
				result[i][j] = (abs(j-arraySize / 2) + 1); 
			
		} 
	} 
		
	// Print the array 
	for(int i = 0; i < arraySize; i++) 
	{ 
		for(int j = 0; j < arraySize; j++) 
		{ 
			cout << result[i][j] << " "; 
		} 
		cout << endl; 
	} 
} 

// Driver Code 
int main() 
{ 
	int n = 3; 

	printPattern(n); 
	return 0; 
} 

// This code is contributed 
// by Rajput-Ji. 
