// https://leetcode.com/problems/maximum-depth-of-binary-tree/

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
    int max=0;
    
    void height_bt(TreeNode* root, int h) {
        if(!root) {
            if(h-1>max) max=h-1;
            return;
        }
        height_bt(root->left,h+1);
        height_bt(root->right,h+1);
    }
    
    int maxDepth(TreeNode* root) {
        height_bt(root,1);
        return max;
    }
};