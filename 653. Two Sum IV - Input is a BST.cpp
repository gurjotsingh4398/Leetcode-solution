// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

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
     bool flag=false;
    
     void inorder(TreeNode* root, unordered_map<int,int> &m,int k) {
        if(!root || flag) return;
        
        inorder(root->left,m,k);
        int val=(k-root->val);
        if(m[val]==1) {
            flag=true;
            return;
        } else {
            m[root->val]=1;
        }
        inorder(root->right,m,k);
    }
    
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int> m;
        inorder(root,m,k);
        return flag;
    }
};