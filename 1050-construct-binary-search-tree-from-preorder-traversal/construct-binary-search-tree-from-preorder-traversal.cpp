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
    int helper(vector<int>& preorder,int left,int right) {
        if(left > right) return left;
        while((right < preorder.size()) && (preorder[right] < preorder[left])) {
            right++;
        }
        return right;
    }
    TreeNode* formation(vector<int>& preorder,int l,int r) {
        if(l > r) return nullptr;
        TreeNode* node = new TreeNode(preorder[l]);
        int x = helper(preorder,l,l+1);
        node->left = formation(preorder,l+1,x - 1);
        node->right = formation(preorder,x,r);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return formation(preorder,0,preorder.size() - 1);
    }
};