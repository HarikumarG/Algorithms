// Print all possible combinations of r elements in a given array of size n

#include <iostream>
#include <vector>
using namespace std;

void allComb(int arr[], int n, int r, vector<int> res, int ind) {
	if(res.size() >= r) {
		for(auto i : res)
			cout<<i<<" ";
		cout<<endl;
		return;
	}

	for(int i = ind; i < n; i++) {
		res.push_back(arr[i]);
		allComb(arr, n, r, res, i+1);
		res.pop_back();
	}

}

int main() {
	int n = 5, r = 3;
	int arr[] = {1, 2, 3, 4, 5};
	vector<int>res;

	allComb(arr, n, r, res, 0);

	return 0;
}