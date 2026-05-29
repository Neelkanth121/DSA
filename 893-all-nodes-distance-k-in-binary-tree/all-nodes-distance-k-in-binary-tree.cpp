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
    void makeParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left != nullptr) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right != nullptr) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        makeParents(root, parent);
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int cur_level = 0;
        while(!q.empty()) {
            int size = q.size();
            if(cur_level == k) break;
            cur_level++;
            for(int i=0;i<size;i++) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if(node->right && !visited[node->right]) {
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if(parent[node] && !visited[parent[node]]) {
                    q.push(parent[node]);
                    visited[parent[node]] = true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};