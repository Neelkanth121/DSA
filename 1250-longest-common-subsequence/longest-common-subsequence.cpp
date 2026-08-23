class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(),vector<int>(text2.size(),-1));
        return helper(text1.size()-1,text2.size()-1,text1,text2,dp);
    }

    int helper(int i,int j, string& s, string& t, vector<vector<int>>& dp) {
        if((i < 0) || (j < 0)) return 0; 

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]) return dp[i][j] = 1 + helper(i-1,j-1,s,t,dp);

        return dp[i][j] = max(helper(i-1,j,s,t,dp), helper(i,j-1,s,t,dp));
    }
};