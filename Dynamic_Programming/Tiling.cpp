#include <iostream>
using namespace std;

int recur(int n) {
	if(n == 1 || n == 2)
		return n;
	int v1 = recur(n-1);
	int v2 = recur(n-2);
	return v1+v2;
}

int main() {
	int N = 4;
	cout<<recur(N)<<endl;
	return 0;
}