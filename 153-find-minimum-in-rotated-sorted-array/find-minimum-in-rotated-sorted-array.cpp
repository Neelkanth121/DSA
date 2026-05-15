class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int ans = INT_MAX;
        while(left <= right) {
            int mid = (left + right) / 2;
            ans = min(ans,nums[mid]);
            if((nums[left] <= nums[mid]) && (nums[left] > nums[right])) {
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return ans;
    }
};