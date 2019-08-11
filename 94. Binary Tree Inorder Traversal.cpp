// https://leetcode.com/problems/binary-tree-inorder-traversal/

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
    void inorder(TreeNode* root, vector<int> &res) {
        if(!root) return;
        
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right,res);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root,res);
        return res;
    }
};

// ---------------------iterative-------------------------------

class Solution {
public:
    void inorder(TreeNode* root, vector<int> &res) {
        stack<TreeNode*> s;
        TreeNode* curr=root;
        while(curr || !s.empty()) {
            while(curr) {
                s.push(curr);
                curr = curr->left;
            }
            curr = s.top();
            s.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root,res);
        return res;
    }
};