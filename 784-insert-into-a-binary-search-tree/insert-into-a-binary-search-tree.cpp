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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) {
            TreeNode* newNode = new TreeNode(val);
            return newNode;
        }
        TreeNode* node = root;
        TreeNode* temp;
        while(node != nullptr) {
            temp = node;
            if(node->val < val) node = node->right;
            else {
                node = node->left;
            }
        }
        TreeNode* newNode = new TreeNode(val);
        if(val > temp->val) temp->right = newNode;
        else{
            temp->left = newNode;
        }
        return root;
    }
};