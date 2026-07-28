class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return helper(nums,nums.size()-1,dp);
    }
    int helper(vector<int>& nums, int index, vector<int>& dp) {
        if(index == 0) return nums[0];
        if(index < 0) return 0;
        if(dp[index] != -1) return dp[index];

        int pick = nums[index] + helper(nums,index - 2,dp);
        int notpick = helper(nums,index-1,dp);

        return dp[index] = max(pick,notpick);
    }
};