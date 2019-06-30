// https://leetcode.com/problems/range-sum-of-bst/

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
    int ans=0;
    void inorder(TreeNode* root, int L, int R) {
        if(!root) return;
        
        inorder(root->left, L, R);
        if(root->val>=L && root->val<=R) ans=ans + root->val;
        inorder(root->right, L, R);
    }
    
    int rangeSumBST(TreeNode* root, int L, int R) {
        inorder(root, L, R);
        return ans;
    }
};