#include <iostream>
#include <vector>
using namespace std;

int minDiff = INT_MAX;
int leftValue, rightValue;
vector<int> leftFinal, rightFinal;

void backtrack(vector<int>arr, vector<int> &leftHalf, vector<int> &rightHalf, int n, int limit, int ind) {
	if((n % 2 == 0 && leftHalf.size() == limit && rightHalf.size() == limit) || (n % 2 != 0 && ( (leftHalf.size() == limit+1 && rightHalf.size() == limit) || (leftHalf.size() == limit && rightHalf.size() == limit+1) ) )) {
		int leftSum = 0, rightSum = 0;
		for(auto i : leftHalf) {
			leftSum += i;
		}
		for(auto i: rightHalf) {
			rightSum += i;
		}
		if(minDiff > abs(leftSum - rightSum)) {
			leftFinal = leftHalf;
			rightFinal = rightHalf;
			leftValue = leftSum;
			rightValue = rightSum;
			minDiff = abs(leftSum - rightSum);
		}
		return;
	}

	for(int i = ind; i < arr.size(); i++) {
		leftHalf.push_back(arr[i]);
		backtrack(arr, leftHalf, rightHalf, n, limit, i+1);
		leftHalf.pop_back();
		rightHalf.push_back(arr[i]);
		backtrack(arr, leftHalf, rightHalf, n, limit, i+1);
		rightHalf.pop_back();
	}

}

int main() {
	vector<int> evenArr = {3, 4, 5, -3, 100, 1, 89, 54, 23, 20};
	vector<int> leftHalf, rightHalf;
	backtrack(evenArr, leftHalf, rightHalf, evenArr.size(), evenArr.size()/2, 0);
	cout<<"Left Half: "<<leftValue<<endl;
	for(auto i : leftFinal)
		cout<<i<<" ";
	cout<<endl;
	cout<<"Right Half: "<<rightValue<<endl;
	for(auto i : rightFinal)
		cout<<i<<" ";
	cout<<endl;
	cout<<endl;

	leftHalf.clear();
	rightHalf.clear();
	minDiff = INT_MAX;
	vector<int>oddArr = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
	backtrack(oddArr, leftHalf, rightHalf, oddArr.size(), oddArr.size()/2, 0);
	cout<<"Left Half: "<<leftValue<<endl;
	for(auto i : leftFinal)
		cout<<i<<" ";
	cout<<endl;
	cout<<"Right Half: "<<rightValue<<endl;
	for(auto i : rightFinal)
		cout<<i<<" ";
	cout<<endl;
	cout<<endl;
	return 0;
}