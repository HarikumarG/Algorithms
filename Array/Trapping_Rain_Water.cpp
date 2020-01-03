#include<bits/stdc++.h>
using namespace std;
int findWater(int a[],int n)
{
	int res = 0;
	int left = 0;
	int right = n-1;
	int leftmax = 0,rightmax = 0;
	
	while(left <= right)
	{
		if(a[left] < a[right])
		{
			if(a[left] > leftmax)
				leftmax = a[left];
			else 
				res += leftmax - a[left];
			left++;
		}
		else
		{
			if(a[right] > rightmax)
				rightmax = a[right];
			else
				res += rightmax - a[right];
			right--;
		}
	}
	return res; 
}
int main() 
{ 
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << "Maximum water that can be accumulated is "
        << findWater(arr, n);  
} 
