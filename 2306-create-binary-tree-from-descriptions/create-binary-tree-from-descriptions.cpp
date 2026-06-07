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
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
        unordered_map<int,TreeNode*> hash;
        unordered_map<int,bool> check;
        for(int i=0;i<d.size();i++) {
            if(hash[d[i][0]] == nullptr) {
                TreeNode* parent = new TreeNode(d[i][0]);
                hash[d[i][0]] = parent;
            }
            if(hash[d[i][1]] == nullptr) {
                TreeNode* child = new TreeNode(d[i][1]);
                hash[d[i][1]] = child;
            }
            if(check[d[i][0]] != true) check[d[i][0]] = false;
            check[d[i][1]] = true;
            if(d[i][2] == 1) {
                hash[d[i][0]]->left = hash[d[i][1]];
            }
            if(d[i][2] == 0) {
                hash[d[i][0]]->right = hash[d[i][1]];
            }
        }
        for(auto it : check) {
            if(it.second == false) return hash[it.first];
        }
        return nullptr;
    }
};