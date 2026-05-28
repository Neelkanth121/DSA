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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>> q;
        long long ans = 0;
        if(root == nullptr) return ans;
        q.push({root,1});
        while(!q.empty()) {
            int size = q.size();
            int minn = q.front().second;
            long long last ,first;
            for(int i=0;i<size;i++) {
                long long val = q.front().second - minn;
                TreeNode* node = q.front().first;
                q.pop();
                if(i == 0) last = val;
                if(i == (size - 1)) first = val;
                if(node->left != nullptr) q.push({node->left,2*val + 1});
                if(node->right != nullptr) q.push({node->right,2*val + 2});
            }
            ans = max(ans,(first - last + 1));
        }
        return ans;
    }
};