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
    TreeNode* build(vector<int>& preorder,int preStart,int preEnd,vector<int>& inorder,int inStart,int inEnd,unordered_map<int,int>& inmap) {
        if((preStart > preEnd) && (inStart > inEnd)) return nullptr;
        TreeNode* root = new TreeNode(preorder[preStart]);
        
        int inroot = inmap[root->val];
        int numsleft = inroot - inStart;

        root->left = build(preorder,preStart + 1,preStart + numsleft,inorder,inStart,inroot - 1,inmap);
        root->right = build(preorder,preStart + numsleft + 1,preEnd,inorder,inroot + 1,inEnd,inmap);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inmap;
        for(int i=0;i<inorder.size();i++) {
            inmap[inorder[i]] = i;
        }
        int presize = preorder.size() - 1;
        int insize = inorder.size() - 1;
        TreeNode* root = build(preorder, 0, presize, inorder, 0, insize, inmap);
        return root;
    }
};