// A simple C++ program for implementation of atoi 
#include <bits/stdc++.h> 

using namespace std; 
int myAtoi(const char *str) 
{ 
	int sign = 1, base = 0, i = 0; 
	// if whitespaces then ignore. 
	while (str[i] == ' ') 
	{ 
	i++; 
	} 
	// sign of number 
	if (str[i] == '-' || str[i] == '+') { 
		sign = 1 - 2 * (str[i++] == '-'); 
	} 
// checking for valid input 
	while (str[i] >= '0' && str[i] <= '9') 
	{ 
		//handling overflow test case 
		if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) { 
			if (sign == 1) return INT_MAX; 
			else return INT_MIN; 
		} 
		base = 10 * base + (str[i++] - '0'); 
	} 
	return base * sign; 
} 

int main() 
{ 
	char str[] = "-123"; 
	int val = myAtoi(str); 
	cout<<val; 
	return 0; 
} 
// This code is contributed by Yogesh shukla. 
