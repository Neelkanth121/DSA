class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return helper(0,0,grid,dp);
    }

    int helper(int row, int col,vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int m = grid.size();
        int n = grid[0].size();
        if((row == m-1) && (col == n-1)) return grid[m-1][n-1];
        if(dp[row][col] != -1) return dp[row][col];
        int down = INT_MAX;
        int right = INT_MAX;
        if(row + 1 < m) {
            down = grid[row][col] + helper(row+1,col,grid,dp);
        }
        if(col + 1 < n) {
            right = grid[row][col] + helper(row,col+1,grid,dp);
        }

        return dp[row][col] = min(down,right);
    }
};