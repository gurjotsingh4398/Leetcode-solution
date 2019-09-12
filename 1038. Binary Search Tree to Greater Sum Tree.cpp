// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

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
    void util(TreeNode* root, int& sum) {
        if(!root) return;
        if(!root->left && !root->right) {
            root->val=sum+root->val;
            sum=root->val;
            return;
        }
        
        util(root->right,sum);
        root->val=sum+root->val;
        sum=root->val;
        util(root->left, sum);
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        int sum=0;
        util(root, sum);
        return root;    
    }
};
