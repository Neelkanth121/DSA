class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return helper(coins.size()-1,amount,coins,dp);
    }

    int helper(int index, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        if(amount == 0) return 1;
        if(index == 0) {
            if(amount % coins[index] == 0) return 1;
            return 0;
        }

        if(dp[index][amount] != -1) return dp[index][amount];

        int notpick = helper(index-1,amount,coins,dp);
        int pick = 0;
        if(amount >= coins[index]) pick = helper(index,amount-coins[index],coins,dp);

        return dp[index][amount] = pick + notpick; 
    }
};