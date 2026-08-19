class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return helper(n-1,m-1,s,t,dp);
    }

    int helper(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        if((i < 0) || (j < 0)) return 0;
        if(j == 0) {
            if(s[i] == t[j]) return 1 + helper(i-1,j,s,t,dp);
        }

        if(dp[i][j] != -1) return dp[i][j];

        int same = 0;
        if(s[i] == t[j]) {
            same = helper(i-1,j-1,s,t,dp);
        }
        int notsame = helper(i-1,j,s,t,dp);

        return dp[i][j] = same + notsame;
    }
};