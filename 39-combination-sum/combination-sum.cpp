class Solution {
public:
    void printCombSum(vector<int>& nums, int target, int index, vector<vector<int>>& ans, vector<int> arr) {
        if(index == nums.size()) {
            if(target == 0) {
                ans.push_back(arr);
            }
            return;
        }
        if(target >= nums[index]) {
            arr.push_back(nums[index]);
            printCombSum(nums, target-nums[index], index, ans, arr);
            arr.pop_back();
        }
        printCombSum(nums, target, index+1, ans, arr);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> arr;
        printCombSum(candidates, target, 0, ans, arr);
        return ans;
    }
};