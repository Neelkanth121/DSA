class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2*k,-1));
        return helper(0,0,k,prices,dp);
    }

    int helper(int index, int check, int k,vector<int>& prices, vector<vector<int>>& dp) {
        if(index >= prices.size()) return 0;
        if(check > ((2 * k) - 1)) return 0;

        if(dp[index][check] != -1) return dp[index][check];

        int pick = 0;
        if(check % 2 == 0) pick = -prices[index] + helper(index+1,check+1,k,prices,dp);
        else pick = prices[index] + helper(index+1,check+1,k,prices,dp);

        int notpick = helper(index+1,check,k,prices,dp);

        return dp[index][check] = max(pick,notpick);
    }
};