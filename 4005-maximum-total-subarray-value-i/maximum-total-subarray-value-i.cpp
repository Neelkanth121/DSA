class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int i=0;i<nums.size();i++) {
            maxi = max(nums[i],maxi);
            mini = min(mini,nums[i]);
        }
        long long dif = maxi - mini;
        return (dif * k);
    }
};