// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

// ----------------------------ist solution---------------------

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
    void dfs(TreeNode *root, int &res, int curr) {
    	if(!root) return;
        
    	int temp = curr*2 + root->val;
    	dfs(root->left, res, temp);
    	dfs(root->right, res, temp);
    	if(!root->left && !root->right) res += temp;
	}
	
    int sumRootToLeaf(TreeNode* root) {
        int res = 0;
        dfs(root, res, 0);
        return res;
    }
};

//-------------------------2nd solution -----------------------------------------

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
    int res = 0;
    
    int binaryToDecimal(vector<int> &bin) {
		int sum = 0;
		for(int i=0; i<bin.size(); i++) {
            sum += (bin[i])*(pow(2, bin.size()-1-i));
        }
		return sum;
	}
    
    void dfs(TreeNode *curr, vector<int> &bin) {
    	if(!curr) return;
        
    	bin.push_back(curr->val);
    	if(!curr->left && !curr->right) res += binaryToDecimal(bin);
    	dfs(curr->left, bin);
    	dfs(curr->right, bin);
		bin.pop_back();	
	}
	
    int sumRootToLeaf(TreeNode* root) {
    	vector<int> bin;
        dfs(root, bin);
        return res;
    }
};