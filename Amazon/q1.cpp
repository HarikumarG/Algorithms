// Given an array of distinct elements and a number x, find if there is a pair with product equal to x.
// https://www.geeksforgeeks.org/pair-with-given-product-set-1-find-if-any-pair-exists/

#include<iostream>
#include<unordered_set>
using namespace std;

bool isProduct(int arr[], int n, int product) {
	if(n < 2)
		return false;
	unordered_set<int> s;

	for(int i = 0; i < n; i++) {
		if(arr[i] == 0) {
			if(product == 0)
				return true;
			else
				continue;
		}

		if(product%arr[i] == 0) {
			if(s.find(product/arr[i]) != s.end())
				return true;
			s.insert(arr[i]);
		}
	}
	return false;
}

int main() {
	int arr[] = {8, 12, 16, 4, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	int product = 96;

	cout<<isProduct(arr, n, product)<<endl;

	return 0;
}