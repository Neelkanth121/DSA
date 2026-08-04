class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++) {
            sum = sum + nums[i];
        }
        // creating dp array
        vector<vector<int>> dp(nums.size(),vector<int> (sum,-1));

        return helper(0,sum,nums.size()-1,nums,dp);
    }

    bool helper(int sum, int total, int index, vector<int>& nums,vector<vector<int>>& dp) {
        if(2 * sum == total) return true;
        if(index == 0) {
            if(2 * (sum + nums[index]) == total) return true;
            else return false;
        }

        if(dp[index][sum] != -1) return dp[index][sum];

        bool notpick = helper(sum,total,index-1,nums,dp);
        bool pick = false;
        if(total > 2 * (sum + nums[index])) {
            pick = helper(sum+nums[index],total,index-1,nums,dp);
        }

        return dp[index][sum] = (pick || notpick);
    }
};