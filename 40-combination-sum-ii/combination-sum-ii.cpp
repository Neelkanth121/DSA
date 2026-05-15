class Solution {
public:
    void printCombSum(vector<int>& nums, int target, vector<vector<int>>& ans, int index, vector<int>& arr) {
        if(target == 0) {
            ans.push_back(arr);
            return;
        }
        for(int i=index;i<nums.size();i++) {
            if((i > index) && (nums[i]==nums[i-1])) continue;
            if(target < nums[i]) {
                break;
            }
            arr.push_back(nums[i]);
            printCombSum(nums, target - nums[i], ans, i+1, arr);
            arr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> arr;
        printCombSum(candidates, target, ans, 0, arr);
        return ans;
    }
};