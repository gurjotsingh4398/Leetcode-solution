// https://leetcode.com/problems/search-in-a-binary-search-tree/

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
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root) {
            if(root->val == val) return root;
            if(root->val > val) root=root->left;
            else root=root->right;
        }
        return NULL;
    }
};
