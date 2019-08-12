// https://leetcode.com/problems/leaf-similar-trees/

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
    void preorder(TreeNode* root, vector<int> &arr) {
        if(!root) return;
        
        if(!root->left && !root->right) {
            arr.push_back(root->val);
            return;
        }
        preorder(root->left, arr);
        preorder(root->right, arr);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1, arr2;
        preorder(root1,arr1);
        preorder(root2,arr2);
        return (arr1 == arr2);
    }
};