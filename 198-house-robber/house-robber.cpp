class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        int even = helper(nums,0,dp);
        int odd = 0;
        if(nums.size() > 1) odd = helper(nums,1,dp);
        return max(odd,even);
    }
    int helper(vector<int>& nums, int index, vector<int>& dp) {
        if(index >= nums.size()) return 0;
        if(dp[index] != -1) return dp[index];
        int maxi = 0;
        for(int i=index + 2;i<nums.size() + 2;i++) {
           int sum = nums[index] + helper(nums,i,dp);
           maxi = max(sum,maxi);
        }
        return dp[index] = maxi;
    }
};