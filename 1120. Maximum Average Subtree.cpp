// https://leetcode.com/problems/maximum-average-subtree/

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
    double maxi=0.0;
    
    pair<double,int> sum(TreeNode* root) {
        if(!root) return make_pair(0,0);
        if(!root->left && !root->right) {
            if(maxi<root->val) maxi=root->val;
            return make_pair(root->val,1);
        }
        
        pair<double,int> s1=sum(root->left);
        pair<double,int> s2=sum(root->right);
        double avg = (s1.first + s2.first + root->val)*1.0/(s1.second + s2.second + 1);
        if(avg>maxi) maxi=avg;
        return make_pair(s1.first + s2.first + root->val, s1.second + s2.second + 1);
        
    }
    
    double maximumAverageSubtree(TreeNode* root) {
        sum(root);
        return maxi;
    }
};