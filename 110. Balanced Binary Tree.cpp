// https://leetcode.com/problems/balanced-binary-tree/

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
    int check(TreeNode* root) {
        if(root==NULL) {
            return 0;
        }
        int h1 = check(root->left);
        if(h1<0) return h1;
        int h2 = check(root->right);
        if(h2<0) return h2;
        if(abs(h2-h1)<=1) return (max(h1,h2)+1);
        else return -1;
    }
    
    bool isBalanced(TreeNode* root) {
        int ans = check(root);
        if(ans<0) return 0;
        return 1;
    }
};

// --------------------------------------2nd solution------------------------------------------------

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
    int check(TreeNode* root) {
        if(!root) return 0;
        if (!root->left && !root->right) return 1;
        
        int h1 = check(root->left);
        if(h1<0) return h1;
        int h2 = check(root->right);
        if(h2<0) return h2;
        if(abs(h2-h1)<=1) return (max(h1,h2)+1);
        else return -1;
    }
    
    bool isBalanced(TreeNode* root) {
        int ans = check(root);
        if(ans<0) return 0;
        return 1;
    }
};