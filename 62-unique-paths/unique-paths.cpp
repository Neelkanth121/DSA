class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n, vector<int> (m,-1));
        return helper(0,0,m,n,dp);
    }

    int helper(int row, int col, int m, int n, vector<vector<int>>& dp) {
        if((row == n-1) && (col == m-1)) return 1;
        if(dp[row][col] != -1) return dp[row][col];
        int right = 0;
        int down = 0;
        if((row + 1 < n) && (col < m)) {
            right = 1 * helper(row+1,col,m,n,dp);
        }
        if((row < n) && (col + 1 < m)) {
            down = 1 * helper(row,col+1,m,n,dp);
        }
        return dp[row][col] = right + down;
    }
};