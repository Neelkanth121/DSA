class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return helper(0,-1,nums,dp);
    }

    int helper(int index, int previndex, vector<int>& nums, vector<vector<int>>& dp) {
        if(index == nums.size()) return 0;

        if(dp[index][previndex + 1] != -1) return dp[index][previndex + 1];

        int pick = 0;
        if((previndex == -1) || (nums[index] > nums[previndex])) pick = 1 + helper(index+1,index,nums,dp);
        int notpick = helper(index+1,previndex,nums,dp);

        return dp[index][previndex + 1] = max(pick,notpick);
    }
};