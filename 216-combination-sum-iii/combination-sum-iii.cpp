class Solution {
public:
    void CombSum(int index, int k, int n, int target, vector<vector<int>>& ans, vector<int>& arr) {
        if (target < 0) {
            return;
        }
        if(index == (n + 1)) {
            if((target == 0) && (arr.size() == k)) {
                ans.push_back(arr);
            }
            return;
        }
        arr.push_back(index);
        target = target - index;
        CombSum(index + 1, k, n, target, ans, arr);
        arr.pop_back();
        target = target + index;
        CombSum(index + 1, k, n, target, ans, arr);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> arr;
        CombSum(1, k, 9, n, ans, arr);
        if(ans.empty()) {
            return {};
        }
        return ans;
    }
};