class Solution {
public:
    int minInsertions(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
       return helper(0,s.size()-1,s,dp);
    }
    int helper(int left, int right, string& s,vector<vector<int>>& dp) {
        if(left > right) return 0;

        if(dp[left][right] != -1) return dp[left][right];

        if(s[left] == s[right]) return dp[left][right] = helper(left+1,right-1,s,dp);

        return dp[left][right] =  1 + min(helper(left+1,right,s,dp),helper(left,right-1,s,dp));
    }
};