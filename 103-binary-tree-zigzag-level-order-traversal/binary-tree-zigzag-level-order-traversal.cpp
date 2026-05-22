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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        q.push(root);
        int count = 0;
        while(!q.empty()) {
            vector<int> levelorder;
            int size = q.size();
            for(int i=0;i<size;i++) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
                levelorder.push_back(node->val);
            }
            if(count%2 != 0) {
                reverse(levelorder.begin(),levelorder.end());
            }
            ans.push_back(levelorder);
            count++;
        }
        return ans;

    }
};