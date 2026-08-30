class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini = nums[0];
        int maxi = nums[0];
        int mni = 0;
        int mxi = 0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] < mini) {
                mini = nums[i];
                mni = i;
            }
            if(nums[i] > maxi) {
                maxi = nums[i];
                mxi = i;
            }
        }
        int left = max(mxi,mni) + 1;
        int right = nums.size() - min(mxi,mni);
        int both = min(mxi,mni) + 1 + nums.size() - max(mxi,mni);

        return min({left,right,both});
    }
};