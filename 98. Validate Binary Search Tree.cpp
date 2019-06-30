// https://leetcode.com/problems/validate-binary-search-tree/

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
    TreeNode *ptr = NULL;
    bool flag=true;
    void inorder(TreeNode *root) {
        if(!root || !flag) return;
        
        inorder(root->left);
        if(!ptr) ptr=root;
        else {
            if(ptr->val<root->val) ptr=root;
            else flag=false;
        }
        inorder(root->right);
    }
    
    bool isValidBST(TreeNode* root) {
        inorder(root);
        return flag;
    }
};