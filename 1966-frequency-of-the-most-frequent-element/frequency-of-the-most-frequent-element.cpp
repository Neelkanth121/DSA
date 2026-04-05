class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = 1;
        int left = 0;
        long long win_sum = 0;
        for(int right = 0;right<nums.size();right++){
            win_sum = win_sum + nums[right];
            while((1LL*nums[right]*(right-left+1)) - win_sum > k){
                win_sum = win_sum - nums[left];
                left++;
            }
            ans = max(ans,right-left+1);
        }
        return ans;

    }
};