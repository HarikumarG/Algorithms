#include<bits/stdc++.h>
using namespace std;
void merge(int a[],int l,int m,int r)
{
	int b[m+r];
	int k=0;
	int i=l;
	int j=m+1;
	while(i<=m && j<=r)
	{
		if(a[i]<a[j])
		{
			b[k++]=a[i++];
		}
		else
		{
			b[k++]=a[j++];
		}
	}
	while(i<=m)
	{
		b[k++]=a[i++];
	}
	while(j<=r)
	{
		b[k++]=a[j++];
	}
    for(int o=l,m=0;o<=r;o++)
    {
    	a[o]=b[m];
    	m++;
    }
}
//O(1) extra space
void merge1(int a[],int l,int m,int r,int maxele)
{
	int i = l;
	int j = m+1;
	int k = l;
	while(i <= m && j <= r)
	{
		if(a[i] % maxele <= a[j] % maxele)
		{
			a[k] = a[k] + (a[i] % maxele) * maxele;
			k++;
			i++;
		}
		else
		{
			a[k] = a[k] + (a[j] % maxele) * maxele;
			k++;
			j++;
		}
	}
	while(i <= m)
	{
		a[k] = a[k] + (a[i] % maxele) * maxele;
		i++;
		k++;
	}
	while(j <= r)
	{
		a[k] = a[k] + (a[j] % maxele) * maxele;
		j++;
		k++;
	}
	for(int p = l; p <= r; p++)
	{
		a[p] = a[p] / maxele;
	}

}

void mergesort(int a[],int l,int r,int maxele)
{
	int m;
	if(l<r)
	{
		m=(l+r)/2;
		mergesort(a,l,m,maxele);
		mergesort(a,m+1,r,maxele);
		//merge(a,l,m,r);
		merge1(a,l,m,r,maxele);
	}
}

/* Iterative mergesort function to sort arr[0...n-1] */
void mergeSort(int arr[], int n) 
{ 
   int curr_size;  // For current size of subarrays to be merged 
                   // curr_size varies from 1 to n/2 
   int left_start; // For picking starting index of left subarray 
                   // to be merged 
  
   // Merge subarrays in bottom up manner.  First merge subarrays of 
   // size 1 to create sorted subarrays of size 2, then merge subarrays 
   // of size 2 to create sorted subarrays of size 4, and so on. 
   for (curr_size=1; curr_size<=n-1; curr_size = 2*curr_size) 
   { 
       // Pick starting point of different subarrays of current size 
       for (left_start=0; left_start<n-1; left_start += 2*curr_size) 
       { 
           // Find ending point of left subarray. mid+1 is starting  
           // point of right 
           int mid = min(left_start + curr_size - 1, n-1); 
  
           int right_end = min(left_start + 2*curr_size - 1, n-1); 
  		   
  		   cout<<left_start<<" "<<mid<<" "<<right_end<<endl;
           // Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end] 
           merge(arr, left_start, mid, right_end); 
       } 
       cout<<endl;
   } 
} 
void printarray(int a[],int len)
{
	cout<<endl;
	for(int i=0;i<len;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int a[]={6,4,5,2,3,1};
	int len=sizeof(a)/sizeof(a[0]);
	printarray(a,len);
	int maxele = *max_element(a,a+len)+1;
	//mergesort(a,0,len-1,maxele);
	mergeSort(a,len);
	printarray(a,len);
	return 0;
}
