class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> temp(nums.size(),0);
        int mini = nums[nums.size()-1];
        temp[nums.size()-1] = mini;
        for(int i=nums.size()-1;i>=0;i--) {
            mini = min(mini,nums[i]);
            temp[i] = mini;
        }

        int maxi = nums[0];
        for(int i=0;i<nums.size();i++) {
            maxi = max(maxi,nums[i]);
            if((maxi - temp[i]) <= k) return i;
        }

        return -1;
    }
};