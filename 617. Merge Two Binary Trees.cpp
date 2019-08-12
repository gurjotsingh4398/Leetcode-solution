// https://leetcode.com/problems/merge-two-binary-trees/

//-----------------------1st solution---------------------------------------------

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
    void merge(TreeNode* t1, TreeNode* t2) {
        t1->val = t1->val + t2->val;
        
        if(t1->left && t2->left) merge(t1->left, t2->left);
        else if(t1->left && !t2->left) {
            t2->left = new TreeNode(0);
            merge(t1->left, t2->left);
            
        }
        else if(!t1->left && t2->left) {
            t1->left = new TreeNode(0);
            merge(t1->left, t2->left);
            
        }
        
        if(t1->right && t2->right) merge(t1->right, t2->right);
        else if(t1->right && !t2->right) {
            t2->right = new TreeNode(0);
            merge(t1->right, t2->right);
            
        }
        else if(!t1->right && t2->right) {
            t1->right = new TreeNode(0);
            merge(t1->right, t2->right);
            
        }
    }
    
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1) return t2;
        if(!t2) return t1;
        
        merge(t1, t2);
        
        return t1;
        
    }
};

//---------------------2nd solution ------------------------------------------

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1) return t2;
        if(!t2) return t1;
        
        t1->val += t2->val;
    
        t1->left = mergeTrees(t1->left,t2->left);
        t1->right = mergeTrees(t1->right,t2->right);
    
        return t1;
    }
};