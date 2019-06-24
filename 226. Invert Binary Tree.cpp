// https://leetcode.com/problems/invert-binary-tree/

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
    void invert(TreeNode* root) {
        if(!root) return;
        if(!root->left && !root->right) return;
        
        invert(root->left);
        invert(root->right);
        TreeNode* tmp=root->right;
        root->right=root->left;
        root->left=tmp;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};