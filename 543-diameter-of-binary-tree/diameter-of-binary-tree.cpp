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
    int maxHeight(TreeNode* root, int& ans) {
        if(root == nullptr) return 0;
        int l = maxHeight(root->left, ans);
        int r = maxHeight(root->right, ans);
        ans = max(ans, (l + r));
        return (1 + max(l,r));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        int ans = INT_MIN;
        maxHeight(root, ans);
        return ans;
    }
};