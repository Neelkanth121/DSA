class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> forward;
        vector<int> backward;
        int product = 1;
        for(auto it : nums) {
            product = product * it;
            forward.push_back(product);
        }
        product = 1;
        for(int i=nums.size()-1;i>=0;i--) {
            product = product * nums[i];
            backward.push_back(product);
        }
        reverse(backward.begin(),backward.end());

        vector<int> ans(nums.size(),-1);
        ans[nums.size()-1] = forward[nums.size() - 2];
        ans[0] = backward[1];
        for(int i=1;i<nums.size()-1;i++) {
            ans[i] = forward[i-1] * backward[i+1];
        }

        return ans;

    }
};