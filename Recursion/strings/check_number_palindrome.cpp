#include <iostream>
using namespace std;

int check(int n, int s) {
	if(n == 0)
		return s;
	return check(n/10,(s*10)+(n%10));
}

int main() {
	int n = 1232;
	int n1 = check(n, 0);
	cout<<endl<<"Result "<<n1<<endl;
	if(n1 == n)
		cout<<"Palindrome"<<endl;
	else
		cout<<"Not Palindrome"<<endl;
	cout<<endl;
	return 0;
}