// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        stack<TreeNode *> lr,rl; //In lr push r first then l and for rl push l first and then r.
        vector<int> tmp;
        lr.push(root);
        while(!lr.empty() || !rl.empty()) {
            while(!lr.empty()) {
                TreeNode *ptr=lr.top();
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
                TreeNode *ptr=rl.top();
                tmp.push_back(ptr->val);
                rl.pop(); 
                if (ptr->right) 
                    lr.push(ptr->right); 
                if (ptr->left) 
                    lr.push(ptr->left); 
            }
            if(!tmp.empty()) {
                ans.push_back(tmp);
                tmp.clear();
            }
        }
        return ans;
        
    }
};