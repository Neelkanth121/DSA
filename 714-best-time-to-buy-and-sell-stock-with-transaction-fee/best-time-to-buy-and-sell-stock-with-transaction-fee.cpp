class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return helper(0,0,fee,prices,dp);
    }

    int helper(int index, int cansell, int fee,vector<int>& prices,vector<vector<int>>& dp) {
        if(index >= prices.size()) return 0;

        if(dp[index][cansell] != -1) return dp[index][cansell];

        int pick = 0;
        if(cansell == 0) pick = -prices[index] + helper(index+1, 1, fee, prices,dp);
        else pick = prices[index] - fee + helper(index + 1,0,fee,prices,dp);

        int notpick = helper(index+1,cansell,fee,prices,dp);

        return dp[index][cansell] = max(pick,notpick); 
    }
};