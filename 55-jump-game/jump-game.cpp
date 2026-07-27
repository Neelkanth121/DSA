class Solution {
public:
    bool canJump(vector<int>& nums) {
        int index = 0;
        vector<int> dp(nums.size()+1,-1);
        return helper(nums,index,dp);
    }

    bool helper(vector<int>& nums, int index, vector<int>& dp) {
        if(index == nums.size() - 1) return true;
        if(index >= nums.size()) return false;
        if(dp[index] != -1) return dp[index];
        for(int i = index + 1;i<=index + nums[index];i++) {
            if(helper(nums,i,dp)) return dp[i] = true;
        }
        return dp[index] = false;
    }
};