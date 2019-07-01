#include<bits/stdc++.h>
using namespace std;
#define MAX_LEN 100
void selectionsortstrings(char arr[][MAX_LEN],int n)
{
	int min_idx;
	char min_str[MAX_LEN];
	for(int i=0;i<n-1;i++)
	{
		min_idx=i;
		strcpy(min_str,arr[i]);
		for(int j=i+1;j<n;j++)
		{
			// If min is greater than arr[j]
			if(strcmp(min_str,arr[j])>0)
			{
				min_idx=j;
				strcpy(min_str,arr[j]);
			}
		}
		if(min_idx!=i)
		{
			char temp[MAX_LEN];
			strcpy(temp,arr[i]);
			strcpy(arr[i],arr[min_idx]);
			strcpy(arr[min_idx],temp);
		}
	}
}
int main()
{
	char arr[][MAX_LEN] = {"GeeksforGeeks", "Practice.GeeksforGeeks","GeeksQuiz"};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<"Before sorting\n\n";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<"\n";
	}
	selectionsortstrings(arr,n);
	cout<<"After sorting\n\n";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<"\n";
	}	
	return 0;
}