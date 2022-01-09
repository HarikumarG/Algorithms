//Find all even length binary sequences with same sum of first and second half bits
//Given a number n, find all binary sequences of length 2n such that sum of first n bits is same as sum of last n bits.
#include <iostream>
#include <string>
using namespace std;

bool checkEqualBits(char* s, int n) {
	int firstHalf = 0, secondHalf = 0;
	for(int i = 0; i < n/2; i++)
		if(s[i] == '1')
			firstHalf++;
	for(int i = n/2; i < n; i++)
		if(s[i] == '1')
			secondHalf++;
	return firstHalf == secondHalf;
}

void permute(char* s, int ind, int n) {
	if(ind == n) {
		//if(checkEqualBits(s, n)) {
			cout<<s<<endl;
		//}
		return;
	}

	s[ind] = '0';
	permute(s, ind+1, n);

	s[ind] = '1';
	permute(s, ind+1, n);
}

int main() {
	int n = 3;
	char s[n];
	permute(s, 0, n);
	cout<<endl;
	return 0;
}