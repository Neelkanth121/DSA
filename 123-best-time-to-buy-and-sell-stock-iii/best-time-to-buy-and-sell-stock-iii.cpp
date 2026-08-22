class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(4,-1));
        return helper(0,0,prices,dp);
    }

    int helper(int index, int check, vector<int>& prices, vector<vector<int>>& dp) {
        if(index >= prices.size()) return 0;
        if(check > 3) return 0;

        if(dp[index][check] != -1) return dp[index][check];

        int pick = 0;
        if(check % 2 == 0) pick = -prices[index] + helper(index+1,check+1,prices,dp);
        else pick = prices[index] + helper(index+1,check+1,prices,dp);

        int notpick = helper(index+1,check,prices,dp);

        return dp[index][check] = max(pick,notpick);
    }
};