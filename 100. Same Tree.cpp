// https://leetcode.com/problems/same-tree/

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
    bool flag=true;
    
    void preorder(TreeNode* root, TreeNode* root2) {
        if(!root && !root2 || !flag) return;
        if(!root && root2 || root && !root2 || root && root2 && root->val!=root2->val) {
            flag=false;
            return;
        }
        preorder(root->left,root2->left);
        preorder(root->right,root2->right);
    }
    
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        preorder(p,q);
        return flag;
    }
};