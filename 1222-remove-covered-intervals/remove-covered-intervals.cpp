class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& nums) {
        vector<bool> hash(nums.size(),false);
        int size = nums.size();
        for(int i=0;i<nums.size();i++) {
            for(int j=0;j<nums.size();j++) {
                if(i == j) continue;
                if(nums[i][0] >= nums[j][0]) {
                    if(nums[i][1] <= nums[j][1]) {
                        if(!hash[i]) {
                            size--;
                            hash[i] = true;
                        }
                    }
                }
            }
        }
        return size;
    }
};