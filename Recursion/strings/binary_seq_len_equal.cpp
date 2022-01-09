//All possible binary numbers of length n with equal sum in both halves
//Given a number n, we need to print all n-digit binary numbers with equal sum in left and right halves. If n is odd, then mid element can be either 0 or 1.
#include <iostream>
using namespace std;

bool checkEqualBits(char* s, int n) {
	int firstHalf = 0, secondHalf = 0;
	for(int i = 0; i < n/2; i++)
		if(s[i] == '1')
			firstHalf++;
	int v = (n%2 == 0) ? n/2 : n/2+1;
	for(int i = v ; i < n; i++)
		if(s[i] == '1')
			secondHalf++;
	return firstHalf == secondHalf;
}

void permute(char* s, int ind, int n) {
	if(ind == n) {
		if(checkEqualBits(s, n)) {
			cout<<s<<endl;
		}
		return;
	}

	s[ind] = '0';
	permute(s, ind+1, n);

	s[ind] = '1';
	permute(s, ind+1, n);
}

int main() {
	int n = 5;
	char s[n];
	permute(s, 0, n);
	cout<<endl;
	return 0;
}