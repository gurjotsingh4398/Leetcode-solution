// https://leetcode.com/problems/binary-tree-right-side-view/

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
    
void levelOrder(TreeNode* root,vector<int>& ans) {
    if(!root) return;
   
    queue<TreeNode*> q1,q2;
    q1.push(root);
    
    while(!q1.empty() || !q2.empty()) {
        if(!q1.empty()) {
            ans.push_back(q1.front()->val);
        }
        while(!q1.empty()) {
            TreeNode *tmp=q1.front();
            q1.pop();
            if(tmp->right) q2.push(tmp->right);
            if(tmp->left) q2.push(tmp->left);
        }
        if(!q2.empty()) {
            ans.push_back(q2.front()->val);
        }
        while(!q2.empty()) {
            TreeNode *tmp=q2.front();
            q2.pop();
            if(tmp->right) q1.push(tmp->right);
            if(tmp->left) q1.push(tmp->left);
        }
    }
    
}
    
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        levelOrder(root, ans);
        return  ans;
    }
};