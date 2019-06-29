// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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
    TreeNode* build(vector<int>& nums, int s, int e) {
        if(s==e) {
            TreeNode *tmp=new TreeNode(nums[s]);
            return tmp;
        }
        if(s>e) return NULL;
        
        int  mid=(s+e)/2;
        TreeNode *root=new TreeNode(nums[mid]);
        root->left=build(nums,s,mid-1);
        root->right=build(nums,mid+1,e);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return NULL;
        return build(nums,0,n-1);      
    }
};