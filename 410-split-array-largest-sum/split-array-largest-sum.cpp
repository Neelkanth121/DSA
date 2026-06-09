class Solution {
public:
    bool isalloc(vector<int>& nums, int k, int mid) {
        int sub = 0;
        int nk = 1;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] > mid) return false;
            if((sub + nums[i]) > mid) {
                sub = nums[i];
                nk++;
            }
            else{
                sub = nums[i] + sub;
            }
        }
        if(nk > k) return false;
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int left = INT_MAX;
        int right = 0;
        for(int i=0;i<nums.size();i++) {
            left = min(left,nums[i]);
            right = right + nums[i];
        }
        int ans = -1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(isalloc(nums,k,mid)) {
                ans = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};