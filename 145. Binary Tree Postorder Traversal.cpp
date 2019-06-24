// https://leetcode.com/problems/binary-tree-postorder-traversal/

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
    vector<int> res;

    void porder(TreeNode* root) {
        if(!root) return;
        
        porder(root->left);
        porder(root->right);
        res.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        porder(root);
        return res;
    }
};