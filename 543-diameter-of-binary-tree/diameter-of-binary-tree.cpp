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
    int maxHeight(TreeNode* root) {
        if(root == nullptr) return 0;
        return (1 + max(maxHeight(root->left),maxHeight(root->right)));
    }
    void findDiameter(TreeNode* root,int& ans) {
        if(root == nullptr) return;
        int l = maxHeight(root->left);
        int r = maxHeight(root->right);
        ans = max(ans,(l + r));
        findDiameter(root->left, ans);
        findDiameter(root->right, ans);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        int ans = INT_MIN;
        findDiameter(root, ans);
        return ans;
    }
};