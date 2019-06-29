// https://leetcode.com/problems/insert-into-a-binary-search-tree/

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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);;
        TreeNode* tmp=root;
        while(1) {
            if(tmp->val > val ) {
                if(tmp->left) tmp=tmp->left;
                else {
                    tmp->left=new TreeNode(val); 
                    break;
                }
            } else {
                if(tmp->right) tmp=tmp->right;
                else {
                    tmp->right=new TreeNode(val); 
                    break;
                }  
            }
        }
        return root;
    }
};