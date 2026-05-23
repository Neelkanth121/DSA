class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        bool ans = true;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>nums[(i+1)%nums.size()]){
                count++;
            }
        }
        if(count>1){
            ans = false;
        }
        return ans;
    }
};