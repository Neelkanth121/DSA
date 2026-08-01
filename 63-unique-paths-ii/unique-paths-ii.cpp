class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(obstacleGrid[n-1][m-1] == 1) return 0;
        vector<vector<int>> dp(n,vector<int> (m,-1));
        return helper(0,0,m,n,dp,obstacleGrid);
    }

    int helper(int row, int col, int m, int n, vector<vector<int>>& dp,vector<vector<int>>& grid) {
        if(grid[row][col] == 1) return 0;
        if((row == n-1) && (col == m-1)) return 1;
        if(dp[row][col] != -1) return dp[row][col];
        int right = 0;
        int down = 0;
        if((row + 1 < n) && (col < m)) {
            right = helper(row+1,col,m,n,dp,grid);
        }
        if((row < n) && (col + 1 < m)) {
            down = helper(row,col+1,m,n,dp,grid);
        }
        return dp[row][col] = right + down;
    }
};