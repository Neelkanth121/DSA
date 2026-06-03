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
    bool isValidBST(TreeNode* root) {
        return helper(root,LLONG_MIN,LLONG_MAX);
    }
    bool helper(TreeNode* root, long long rangeLeft, long long rangeRight) {
        if(root == nullptr) return true;
        if((root->val >= rangeRight) || (root->val <= rangeLeft)) return false;
        bool left = helper(root->left,rangeLeft,root->val);
        bool right = helper(root->right,root->val,rangeRight);
        if(!left || !right) return false;
        return true;
    }
};