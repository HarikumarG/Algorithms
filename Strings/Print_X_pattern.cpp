// CPP program to print cross pattern 
#include<bits/stdc++.h> 
using namespace std; 

// Function to print given string in 
// cross pattern 
void pattern(string str, int len){ 
	
	// i and j are the indexes of characters 
	// to be displayed in the ith iteration 
	// i = 0 initially and go upto length of 
	// string 
	// j = length of string initially 
	// in each iteration of i, we increment 
	// i and decrement j, we print character 
	// only of k==i or k==j 
	for (int i = 0; i < len; i++) 
	{ 
		int j = len -1 - i; 
		for (int k = 0; k < len; k++) 
		{ 
			if (k == i || k == j) 
				cout << str[i]; 
			else
				cout << " "; 
		} 
		cout << endl;	 
	} 
} 

// driver code 
int main () 
{ 
	string str = "apple"; 
	int len = str.size(); 
	pattern(str, len); 

	return 0; 
} 
// This code is contributed by Satinder Kaur 
