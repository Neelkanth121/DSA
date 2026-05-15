class Solution {
public:
    void printSubSet(vector<int>& nums, int index, vector<vector<int>>& ans, vector<int>& arr) {
        if(index == nums.size()) {
            return;
        }
        for(int i = index;i<nums.size();i++) {
            if((i > index) && (nums[i] == nums[i-1])) continue;
            arr.push_back(nums[i]);
            printSubSet(nums, i+1, ans, arr);
            ans.push_back(arr);
            arr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> arr;
        vector<vector<int>> ans;
        ans.push_back({});
        printSubSet(nums, 0, ans, arr);
        return ans;
    }
};