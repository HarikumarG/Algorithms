//Generate all possible sorted arrays from alternate elements of two given sorted arrays

#include <iostream>
#include <vector>
using namespace std;

void generateArray(int A[], int B[], vector<int> curr, int a, int b, int n, int m, bool flag) {
	if(flag) {
		if(curr.size() > 0) {
			for(auto i : curr)
				cout<<i<<" ";
			cout<<endl;
		}
		for(int i = a; i < n; i++) {
			if(!curr.size()) {
				curr.push_back(A[i]);
				generateArray(A, B, curr, i+1, b, n, m, !flag);
				curr.pop_back();
			} else {
				if(A[i] > curr[curr.size()-1]) {
					curr.push_back(A[i]);
					generateArray(A, B, curr, i+1, b, n, m, !flag);
					curr.pop_back();
				}
			}
		}
	} else {
		for(int i = b; i < m; i++) {
			if(B[i] > curr[curr.size()-1]) {
				curr.push_back(B[i]);
				generateArray(A, B, curr, a, i+1, n, m, !flag);
				curr.pop_back();
			}
		}
	}
}

int main() {
	int A[] = {10, 15, 25};
	int B[] = {1, 5, 20, 30};
	int n = sizeof(A)/sizeof(A[0]);
	int m = sizeof(B)/sizeof(B[0]);
	vector<int> curr;
	generateArray(A, B, curr, 0, 0, n, m, true);
	return 0;
}