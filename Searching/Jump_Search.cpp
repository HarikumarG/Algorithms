#include<bits/stdc++.h>
using namespace std;
bool jumpSearch(int arr[],int x,int n){

    int step = 0;
    int prev = 0;
    while(arr[step] < x) {
        prev = step;
        step = step + sqrt(n);
    }
    while(prev <= step) {
        if(arr[prev] == x) {
            return true;
        }
        prev++;
    }
    return false;
}
int main() {
    int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21,
                34, 55, 89, 144, 233, 377, 610 };
    int x = -3;
    int n = sizeof(arr) / sizeof(arr[0]);

    bool isfound = jumpSearch(arr, x, n);

    if(isfound == true) {
        cout<<"Found";
    } else {
        cout<<"Not Found";
    }
    return 0;
}
