#include<bits/stdc++.h>
using namespace std;
void swap(int nums[], int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

 void reverse(int nums[], int start,int n) {
        int i = start;
        int j = n - 1;
        while (i < j) {
            swap(nums, i, j);
            i++;
            j--;
        }
    }
void nextPermutation(int nums[],int n) {
        int i = n - 2;
        while (i >= 0 && nums[i + 1] <= nums[i]) {
            i--;
        }
        if (i >= 0) {
            int j = n - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            swap(nums, i, j);
        }
        reverse(nums, i + 1,n);
    }
int main()
{
    int nums[]={1,2,3};
    int n=sizeof(nums)/sizeof(nums[0]);
    nextPermutation(nums,n);
    for(int i=0;i<n;i++)
        cout<<nums[i]<<" ";
}
