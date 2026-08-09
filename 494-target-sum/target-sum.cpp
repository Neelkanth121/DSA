class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(nums.size()-1,target,nums);
    }

    int helper(int index, int target, vector<int>& nums) {
        if(index < 0) return (target == 0);

        int notpick = helper(index-1,target + nums[index],nums);
        int pick = helper(index-1,target - nums[index],nums);

        return pick + notpick;
    }
};