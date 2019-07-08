// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        if(root->val==p->val || root->val==q->val) return root;
        
        TreeNode  *lca_left = lowestCommonAncestor(root->left, p, q);
        TreeNode  *lca_right = lowestCommonAncestor(root->right, p, q);
        if(lca_left && lca_right) return root;
        return lca_left ? lca_left : lca_right;
    }
};