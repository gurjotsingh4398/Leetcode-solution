// https://leetcode.com/problems/sum-of-left-leaves/

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
    void dfs(TreeNode* root, int &sum, bool leftChild) {
        if(!root) return;
        
        if(!root->left && !root->right && leftChild) {
            sum+=root->val;
        }
        dfs(root->left, sum, true);
        dfs(root->right, sum, false);
        
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        dfs(root, sum, false);
        return sum;
    }
};