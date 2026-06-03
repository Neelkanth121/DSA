/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* root, vector<int>& nums) {
        if(root == nullptr) return;
        helper(root->left,nums);
        nums.push_back(root->val);
        helper(root->right,nums);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int> hash;
        vector<int> nums;
        helper(root,nums);
        for(int i=0;i<nums.size();i++) {
            if(hash[k - nums[i]] > 0) return true;
            hash[nums[i]]++;
        } 
        return false;
    }
};