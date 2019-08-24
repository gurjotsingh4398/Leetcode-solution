// https://leetcode.com/problems/path-sum/

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
    void dfs(TreeNode* root, int sum, int target, bool &ans) {
        if(!root || ans) return;
        if(!root->left && !root->right && sum+root->val==target) {
            ans=true;
            return;
        }
        sum+=root->val;
        dfs(root->left, sum, target, ans);
        dfs(root->right, sum, target, ans);
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        bool ans=false;
        dfs(root, 0, sum, ans);
        return ans;
    }
};