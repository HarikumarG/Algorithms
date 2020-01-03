#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n = 10;
	int k = 2;
	int fact[n+1];
	fact[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		fact[i] = fact[i-1] * i;	
	} 
	cout<<fact[n]/fact[n-k];
	return 0;
}
//O(n) time and O(1) space solution
//int P = 1; 
//  
//    // Compute n*(n-1)*(n-2)....(n-k+1) 
//    for (int i = 0; i < k; i++) 
//        P *= (n-i) ; 
//  
//    return P; 
