#include <iostream>
using namespace std;

int calAtoi(string num, int n) {
	if(n == 1)
		return num[n-1] - '0';
	return (10 * calAtoi(num, n-1) + num[n-1] - '0');
}

int main() {
	string num = "12345";
	int res = calAtoi(num, num.length());
	cout<<res<<endl<<endl;
	return 0;
}