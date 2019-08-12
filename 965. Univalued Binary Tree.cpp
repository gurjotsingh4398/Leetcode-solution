// https://leetcode.com/problems/univalued-binary-tree/

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
    void valid(TreeNode* root, bool &ans, int &val) {
        if(!root || !ans) return;
        
        if(val!=root->val) ans=false;
        valid(root->left, ans, val);
        valid(root->right, ans, val);
    }
    
    bool isUnivalTree(TreeNode* root) {
        bool ans=true;
        valid(root, ans, root->val);
        return ans;
    }
};