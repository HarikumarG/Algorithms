#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool checkPalindrome(string s) {
	for(int i = 0,j = s.length()-1; i <= j; i++,j--) {
		if(s[i] != s[j])
			return false;
	}
	return true;
}

void allPart(string s, int start, vector<string>curr) {
	if(start >= s.length()) {
		for(auto i : curr)
			cout<<i<<" ";
		cout<<endl;
		return;
	}

	for(int i = start; i < s.length(); i++) {
		string subString = s.substr(start, i-start+1);
		// cout<<subString<<endl;
		if(checkPalindrome(subString)) {
			curr.push_back(subString);
			allPart(s, i+1, curr);
			curr.pop_back();
		}
	}
}

int main() {

	string s = "nitin";
	vector<string>curr;
	allPart(s, 0, curr);
	cout<<endl;
	return 0;
}