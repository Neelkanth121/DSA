class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int ans = nums[0];
        while((left < nums.size()) && (nums[left] == nums[right])) {
            left++;
        }
        while(left <= right) {
            int mid = (left + right) / 2;
            ans = min(nums[mid], ans);
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