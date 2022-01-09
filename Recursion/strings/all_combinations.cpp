#include <iostream>
#include <vector>
#include <string>
using namespace std;

void allComb(string s, string res, int k) {
	
	if(res.length() >= k) {
		cout<<res<<endl;
		return;
	}

	for(int i = 0; i < s.length(); i++) {
		res += s[i];
		allComb(s, res, k);
		res.pop_back();
	}

}

int main() {
	string s = "ab";
	int k = 3;
	allComb(s, "", k);
	return 0;
}