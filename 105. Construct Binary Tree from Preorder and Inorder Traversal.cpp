// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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
    int pi=0;
    
    TreeNode* build(vector<int>& pre, int s, int e, unordered_map<int, int> &m) {
        if (s>e) return NULL; 
        int val=pre[pi];
        pi++;
        TreeNode* tmp=new TreeNode(val);  
        int in = m[val];
        tmp->left=build(pre, s, in-1, m);  
        tmp->right=build(pre, in+1, e, m);  
        return tmp;  
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=inorder.size();
        if(n==0) return NULL;
        
        unordered_map<int, int> m;
        for (int i=0;i<n;i++) {
            m[inorder[i]] = i;
        }
 
        return build(preorder,0,n-1,m);
    }
};
