class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp;
        for(int i=0;i<n;i++) {
            vector<int> temp;
            for(int j=0;j<=i;j++) {
                temp.push_back(INT_MAX);
            }
            dp.push_back(temp);
        }
        return helper(0,0,triangle,dp);
    }

    int helper(int index, int level, vector<vector<int>>& triangle,vector<vector<int>>& dp) {
        if(level == triangle.size() -1) return triangle[level][index];
        
        if(dp[level][index] != INT_MAX) return dp[level][index];

        int right = triangle[level][index] + helper(index+1,level+1,triangle,dp);
        int down = triangle[level][index] + helper(index,level+1,triangle,dp);

        return dp[level][index] = min(right,down);
    }
};