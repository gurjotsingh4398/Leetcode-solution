// https://leetcode.com/problems/recover-binary-search-tree/

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
    void inorder(TreeNode* &root, TreeNode* &prev, TreeNode* &ptr1, TreeNode* &ptr2) {
        if(!root) return;
        
        inorder(root->left, prev, ptr1, ptr2);
        if(prev && prev->val>root->val) {
            if(!ptr1) ptr1 = prev;
            ptr2 = root;
        }
        prev = root;
        inorder(root->right, prev, ptr1, ptr2);
    }
    
    void recoverTree(TreeNode* root) {
        TreeNode *prev=NULL, *ptr1=NULL, *ptr2=NULL;
        inorder(root,prev, ptr1, ptr2);
        if(ptr1) swap(ptr1->val, ptr2->val);
    }
};