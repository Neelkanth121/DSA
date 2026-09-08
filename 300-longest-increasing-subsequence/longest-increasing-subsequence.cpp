class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return helper(1,0,nums,dp);
    }

    int helper(int index, int previndex, vector<int>& nums, vector<vector<int>>& dp) {
        if(index-1 >= nums.size()) return 0;

        if(dp[index][previndex] != -1) return dp[index][previndex];

        int pick = 0;
        if((previndex == 0) || (nums[index - 1] > nums[previndex - 1])) pick = 1 + helper(index+1,index,nums,dp);
        int notpick = helper(index+1,previndex,nums,dp);

        return dp[index][previndex] = max(pick,notpick);
    }
};