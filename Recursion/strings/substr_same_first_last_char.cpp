//Recursive solution to count substrings with same first and last characters

#include <iostream>
#include <string>
using namespace std;

bool checkSameChar(string s) {
	if(s[0] == s[s.length()-1])
		return true;
	return false;
}

void generateSubString(string s, int start, int end) {
	if(end >= s.length())
		return;
	string subString = s.substr(start, end-start+1);
	if(checkSameChar(subString)) {
		cout<<subString<<endl;
	}
	generateSubString(s, start, end+1);
}

int main() {
	string s = "abcab";
	for(int i = 0; i < s.length(); i++) {
		generateSubString(s, i, i);
	}
	return 0;
}