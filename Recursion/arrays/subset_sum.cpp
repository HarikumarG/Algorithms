#include <iostream>
#include <vector>
using namespace std;

void subsetSum(int arr[], int n, int sum, vector<int> res, int ind, int currSum) {
	if(currSum > sum) {
		return;
	}
	if(currSum == sum) {
		for(auto i :  res)
			cout<<i<<" ";
		cout<<endl;
		return;
	}

	for(int i = ind; i < n; i++) {
		res.push_back(arr[i]);
		subsetSum(arr, n, sum, res, i+1, currSum+arr[i]);
		res.pop_back();
	}
}

bool checkSubset(int arr[], int n, int sum, int ind, int currSum) {
	if(currSum > sum) {
		return false;
	}
	if(currSum == sum) {
		return true;
	}

	for(int i = ind; i < n; i++) {
		if(checkSubset(arr, n, sum, i+1, currSum+arr[i])) {
			return true;
		}
	}
	return false;
}

int main() {
	int arr[] = {3, 34, 4, 12, 5, 2};
	int n = sizeof(arr)/sizeof(arr[0]);
	int sum = 9;
	//to print all possibility
	//vector<int> res;
	//subsetSum(arr, n, sum, res, 0, 0);	
	// cout<<endl;
	// cout<<endl;
	cout<<checkSubset(arr, n, sum, 0, 0)<<endl<<endl;
	return 0;
}