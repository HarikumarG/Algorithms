#include<bits/stdc++.h>
using namespace std;
int main()
{
	int arr[] = {-5, 1, 4, -7, 10, -7, 0, 7, 3, 0, -2, -5, -3, -6, 4, -7, -8, 0, 4, 9, 4, 1, -8, -6, -6, 0, -9, 5, 3, -9, -5, -9, 6, 3, 8, -10, 1, -2, 2, 1, -9, 2, -3, 9, 9, -10, 0, -9, -2, 7, 0, -4, -3, 1, 6, -3};
	int n = sizeof(arr)/sizeof(arr[0]);
	sort(arr,arr+n);
	for(int i = 0; i < n; i++)
		cout<<arr[i]<<" ";
}
