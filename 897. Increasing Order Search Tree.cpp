// https://leetcode.com/problems/increasing-order-search-tree/


//-------------------1st solution ---------------------------------

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
   TreeNode* curr;
   void inorder(TreeNode* root) {
        if(!root) return;
       
        inorder(root->left);
        root->left = NULL; 
        curr->right = root;
        curr = curr->right;
        inorder(root->right);
    } 
    
    TreeNode* increasingBST(TreeNode* root) {
        curr = new TreeNode(0); 
        TreeNode* ans = curr;
        inorder(root); 
        return ans->right;
    }
};


//-------------------2nd solution ---------------------------------

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
    void inorder(TreeNode *node, vector<int> &arr) {
        if (!node) return;
        
        inorder(node->left, arr);
        arr.push_back(node->val);
        inorder(node->right, arr);
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> arr;
        inorder(root, arr);
        TreeNode *rt = new TreeNode(0), *curr=rt;
        for(int n : arr) {
            curr->right = new TreeNode(n);
            curr = curr->right;
        }
        return rt->right;
    }
};