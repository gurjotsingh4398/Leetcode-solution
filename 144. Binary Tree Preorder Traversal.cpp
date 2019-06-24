// https://leetcode.com/problems/binary-tree-preorder-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> res;
    
    void preorder(TreeNode* root) {
        if(!root) return;
        
        res.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return res;
    }
};