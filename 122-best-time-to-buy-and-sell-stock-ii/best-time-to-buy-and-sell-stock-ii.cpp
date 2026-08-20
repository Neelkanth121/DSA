class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int> (2,-1));
        return helper(0,0,prices,dp);
    }

    int helper(int index, int check, vector<int>& prices,vector<vector<int>>& dp) {
        if(index >= prices.size()) return 0;
        int pick = 0;

        if(dp[index][check] != -1) return dp[index][check];

        if(check) pick = prices[index] + helper(index+1,0,prices,dp);
        else pick = -prices[index] + helper(index+1,1,prices,dp);

        int notpick = helper(index+1,check,prices,dp);

        return dp[index][check] = max(pick,notpick);
    }
};