#include<bits/stdc++.h>
using namespace std;
bool binarysearch(int arr[],int l,int r,int x){
    while(r >= l){
        int mid = l + (r-l)/2;
        if(arr[mid] == x)
            return true;
        else if (arr[mid] > x)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return false;
}
bool exp(int arr[],int n,int x){
    if(arr[0] == x)
        return true;
    int i = 1;
    while(i < n && arr[i] <= x){
        i = i * 2;
    }
    return binarysearch(arr,i/2,min(i,n),x);
}
int main(){
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int x = 40;
    bool res = exp(arr,n,x);
    res == true? cout<<"Found" : cout<<"Not Found";
    return 0;
}
