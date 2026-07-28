class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> dp1(nums.size(),-1);
        vector<int> dp2(nums.size(),-1);
        vector<int> temp1, temp2;
        for(int i=0;i<nums.size();i++) {
            if(i != 0) temp1.push_back(nums[i]);
            if(i != nums.size()-1) temp2.push_back(nums[i]);
        }

        return max(helper(temp1,temp1.size() - 1,dp1),helper(temp2,temp2.size() - 1,dp2));
    }

    int helper(vector<int>& nums, int index, vector<int>& dp) {
        if(index == 0) return nums[0];
        if(index < 0) return 0;
        if(dp[index] !=  -1) return dp[index];

        int pick = nums[index] + helper(nums,index - 2,dp);
        int notpick = helper(nums,index-1,dp);

        return dp[index] = max(pick,notpick);
    }
};