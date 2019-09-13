// https://leetcode.com/problems/maximum-binary-tree/

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
    int maxInRange(vector<int>& nums, int l, int r) {
        int max_i=l;
        for(int i=l;i<r;i++) {
            if(nums[i]>nums[max_i]) max_i=i; 
        }
        return max_i;
    }
    
    TreeNode* util(vector<int>& nums, int l, int r) {
        if(l==r) return NULL;
        
        int mx=maxInRange(nums, l, r);
        TreeNode* root=new TreeNode(nums[mx]);
        root->left= util(nums, l, mx);
        root->right= util(nums, mx+1, r);
        return root;
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return util(nums, 0, nums.size());
    }
};