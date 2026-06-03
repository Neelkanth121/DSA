/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return root;
        while(root != nullptr) {
            int pv = p->val;
            int qv = q->val;
            int v = root->val;
            if((pv >= v) && (qv <= v)) return root;
            else if((pv <= v) && (qv >= v)) return root;
            else if((pv < v) && (qv < v)) root = root->left;
            else if((pv > v) && (qv > v)) root = root->right;
        }
        return root;
    }
};