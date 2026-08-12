class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t = "";
        for(int i=s.size()-1;i>=0;i--) {
            t += s[i];
        }
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        return helper(s.size()-1,s.size()-1,s,t,dp);
    }

    int helper(int i, int j, string& s, string& t,vector<vector<int>>& dp) {
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]) return dp[i][j] = 1 + helper(i-1,j-1,s,t,dp);

        return dp[i][j] = max(helper(i-1,j,s,t,dp),helper(i,j-1,s,t,dp));
    }
};