// https://leetcode.com/problems/diameter-of-binary-tree/

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
    int maxi=0;

    int height(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        
        int h1 = height(root->left);
        int h2 = height(root->right);
        if(h1+h2>maxi) maxi=h1+h2;
        return max(h1,h2) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        height(root);
        return maxi;
    }
};