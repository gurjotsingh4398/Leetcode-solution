// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    int pi=0;
    
    TreeNode* build(vector<int>& pre, int s, int e, unordered_map<int, int> &m) {
        if (s>e) return NULL; 
        int val=pre[pi];
        pi++;
        TreeNode* tmp=new TreeNode(val);  
        int in = m[val];
        tmp->right=build(pre, in+1, e, m);  
        tmp->left=build(pre, s, in-1, m);  
        return tmp;  
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        if(n==0) return NULL;
        
        unordered_map<int, int> m;
        for (int i=0;i<n;i++) {
            m[inorder[i]] = i;
        }
 
        reverse(postorder.begin(), postorder.end());
        return build(postorder,0,n-1,m);
        
    }
};