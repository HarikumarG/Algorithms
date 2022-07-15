#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int,int> memo;

int topDown(vector<int> nums, int n) {

    if(n == 0) {
        return nums[0];
    }

    if(n == 1) {
        return max(nums[0], nums[1]);
    }

    if(memo.find(n) == memo.end()) {
        memo[n] = max(topDown(nums, n-1), topDown(nums, n-2)+nums[n]);
    }

    return memo[n];

}

int bottomUp(vector<int> nums, int n) {
    if(n == 0) {
        return 0;
    }

    if(n == 1) {
        return nums[0];
    }

    int dp[n];

    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for(int i = 2; i < n; i++) {
        dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
    }

    return dp[n-1];
}

int main() {
    vector<int> nums = {2, 7, 9, 3, 1};
    cout<<topDown(nums, nums.size()-1)<<endl;
    cout<<bottomUp(nums, nums.size())<<endl;
    return 0;
}