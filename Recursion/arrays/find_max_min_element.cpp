#include <iostream>
#include <algorithm>
using namespace std;

void findMinMax(int arr[], int n, int ind, int &maxEle, int &minEle) {
	if(ind >= n)
		return;

	maxEle = max(arr[ind], maxEle);
	minEle = min(arr[ind], minEle);

	findMinMax(arr, n, ind+1, maxEle, minEle);
}

int main() {
	int n = 5;
	int arr[] = {5, 2, 1, 4, 3};
	int min = INT_MAX;
	int max = INT_MIN;
	findMinMax(arr, n, 0, max, min);
	cout<<"Min "<<min<<" Max "<<max<<endl;
	return 0;
}