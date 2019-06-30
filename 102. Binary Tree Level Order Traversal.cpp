// https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode *> lr,rl;
        vector<int> tmp;
        lr.push(root);
        while(!lr.empty() || !rl.empty()) {
            while(!lr.empty()) {
                TreeNode *ptr=lr.front();
                tmp.push_back(ptr->val);
                lr.pop(); 
                if (ptr->left) 
                    rl.push(ptr->left); 
                if (ptr->right) 
                    rl.push(ptr->right); 
            }
            if(!tmp.empty()) {
                ans.push_back(tmp);
                tmp.clear();
            }
            while(!rl.empty()) {
                TreeNode *ptr=rl.front();
                tmp.push_back(ptr->val);
                rl.pop(); 
                if (ptr->left) 
                    lr.push(ptr->left); 
                if (ptr->right) 
                    lr.push(ptr->right); 
            }
            if(!tmp.empty()) {
                ans.push_back(tmp);
                tmp.clear();
            }
        }
        return ans;
    }
};