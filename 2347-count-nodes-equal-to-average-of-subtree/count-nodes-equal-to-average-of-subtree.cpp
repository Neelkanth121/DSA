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
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        helper(root,ans);
        return ans;
    }

    pair<int,int> helper(TreeNode* root, int& ans) {
        int sum = 0;
        int count = 0;
        if(root->left) {
            pair<int,int> temp = helper(root->left,ans);
            sum = sum + temp.first;
            count = count + temp.second;
        }
        if(root->right) {
            pair<int,int> temp1 = helper(root->right,ans);
            sum = sum + temp1.first;
            count = count + temp1.second; 
        }
        int avg = (root->val + sum) / (count + 1);
        if(avg == root->val) ans++;
        return {root->val + sum, count+1};
    }
};