#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int recur(vector<int> cost, int n) {
    if(n < 0) {
        return 0;
    }

    if(n == 0) {
        return cost[0];
    }

    if(n == 1) {
        return cost[1];
    }

    return cost[n] + min(recur(cost, n-1), recur(cost, n-2));

}

int topDown(vector<int> cost, int n, unordered_map<int,int>& memo) {
    if(n < 0) {
        return 0;
    }

    if(n == 0) {
        return cost[0];
    }

    if(n == 1) {
        return cost[1];
    }

    if(memo.find(n) != memo.end()) {
        return memo[n];
    }

    memo[n] = cost[n] + min(topDown(cost, n-1, memo), topDown(cost, n-2, memo));
    return memo[n];

}

int bottomUp(vector<int> cost, int n) {
    
    int dp[n];
    dp[0] = cost[0];
    dp[1] = cost[1];

    for(int i = 2; i < n; i++) {
        dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
    }

    return min(dp[n-1], dp[n-2]);
}

int main() {
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    //vector<int> cost = {10,15,20};

    int result = INT_MAX;
    
    result = min(recur(cost, cost.size()-1), recur(cost, cost.size()-2));
    cout<<endl<<result<<endl;

    unordered_map<int,int> memo;
    result = min(topDown(cost, cost.size()-1, memo), topDown(cost, cost.size()-2, memo));
    cout<<endl<<result<<endl;

    result = bottomUp(cost, cost.size());
    cout<<endl<<result<<endl;
    return 0;
}