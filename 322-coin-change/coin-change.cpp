class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<vector<int>> dp(coins.size(),vector<int> (amount+1,-1));
        int ans = helper(coins.size()-1,amount,coins,dp);
        if(ans == INT_MAX) return -1;
        return ans;
    }

    int helper(int index, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if(amount == 0) return 0;
        if(index == 0) {
            if(amount % coins[index] == 0) return amount / coins[index];
            return INT_MAX;
        }

        if(dp[index][amount] != -1) return dp[index][amount];

        int notpick = helper(index-1,amount,coins,dp);
        int pick = INT_MAX;
        if(amount >= coins[index]) {
            int result = helper(index,amount - coins[index],coins,dp);
            if(result != INT_MAX) pick = 1 + result;
        }

        return dp[index][amount] = min(pick,notpick);
    }
};