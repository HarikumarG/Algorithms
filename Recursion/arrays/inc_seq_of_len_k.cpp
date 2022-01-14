//Print all increasing sequences of length k from first n natural numbers

#include <iostream>
using namespace std;

void findIncSeq(int arr[], int k, int n, int &len) {
	if(len >= k) {
		for(int i = 0; i < k; i++)
			cout<<arr[i]<<" ";
		cout<<endl;
		return;
	}

	int i = (len == 0) ? 1 : arr[len-1] + 1;
	
	len++;

	for(; i <= n; i++) {
		//len++;
		arr[len - 1] = i;
		findIncSeq(arr, k, n, len);
		//len--;
	}

	len--;

}

int main() {
	int k = 3, n = 4;
	int arr[k];
	int len = 0;
	findIncSeq(arr, k, n, len);
	return 0;
}