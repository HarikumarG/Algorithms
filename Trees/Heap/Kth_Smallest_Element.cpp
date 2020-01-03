//using minheap 
#include<bits/stdc++.h>
using namespace std;
int size;
//void minheapify(int arr[],int i)
//{
//	int l = 2*i + 1;
//	int r = 2*i + 2;
//	int smallest = i;
//	if(l < size && arr[l] < arr[i])
//		smallest = l;
//	if(r < size && arr[r] < arr[smallest])
//		smallest = r;
//	if(smallest != i)
//	{
//		swap(arr[i],arr[smallest]);
//		minheapify(arr,smallest);
//	}
//}
//int extractmin(int arr[])
//{
//	if(size == 0)
//		return INT_MAX;
//	int root = arr[0];
//	if(size > 1)
//	{
//		arr[0] = arr[size - 1];
//		minheapify(arr,0);
//	}
//	size--;
//	return root;
//}
//int kthSmallest(int arr[],int k)
//{
//	int i = (size - 1)/2;
//	while(i >= 0)
//	{
//		minheapify(arr,i);
//		i--;
//	}
//	for(int j = 0; j < k-1; j++)
//	{
//		extractmin(arr);
//	}
//	return arr[0]; 
//	
//}
//int main()
//{
//	int arr[] = {12,3,5,7,19};
//	int n = sizeof(arr)/sizeof(arr[0]);
//	size = n;
//	int k = 2;
//	cout<<kthSmallest(arr,k);
//}
//using maxheap
void maxheapify(int arr[],int i)
{
	int l = 2*i + 1;
	int r = 2*i + 2;
	int largest = i;
	if(l < size && arr[l] > arr[i])
		largest = l;
	if(r < size && arr[r] > arr[largest])
		largest = r;
	if(largest != i)
	{
		swap(arr[i],arr[largest]);
		maxheapify(arr,largest);
	}
}
int kthSmallest(int arr[],int k)
{
	int i = (size - 1)/2;
	while(i >= 0)
	{
		maxheapify(arr,i);
		i--;
	}
	for(int j = k; j < size; j++)
	{
		if(arr[j] < arr[0])
		{
			arr[0] = arr[j];
			maxheapify(arr,0);
		}
	}
	return arr[0]; 	
}
int main()
{
	int arr[] = {12,3,5,7,19};
	int n = sizeof(arr)/sizeof(arr[0]);
	size = n;
	int k = 2;
	cout<<kthSmallest(arr,k);
}
