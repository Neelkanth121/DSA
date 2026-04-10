class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return (count_subarray(nums,goal) - count_subarray(nums,goal-1));
    }
    int count_subarray(vector<int> nums, int goal){
        if(goal<0){
            return 0;
        }
        int l = 0;
        int r = 0;
        int sum = 0;
        int len = 0;
        while(r<nums.size()){
            sum = sum + nums[r];
            if(sum<=goal){
                len = len+(r-l+1);
                r++;
            }
            else{
                sum = sum - nums[l];
                sum = sum - nums[r];
                l++;
            }
        }
        return len;
    }
};