// https://leetcode.com/problems/average-of-levels-in-binary-tree/

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode *> lr,rl;
        double tmp=0;
        int count=0;
        lr.push(root);
        while(!lr.empty() || !rl.empty()) {
            while(!lr.empty()) {
                TreeNode *ptr=lr.front();
                lr.pop(); 
                tmp+=ptr->val;
                count++;
                if (ptr->left) 
                    rl.push(ptr->left); 
                if (ptr->right) 
                    rl.push(ptr->right); 
            }
            if(count!=0) {
                ans.push_back(tmp/count);
                tmp=0;
                count=0;
            }
            while(!rl.empty()) {
                TreeNode *ptr=rl.front();
                rl.pop(); 
                tmp+=ptr->val;
                count++;
                if (ptr->left)
                    lr.push(ptr->left); 
                if (ptr->right) 
                    lr.push(ptr->right); 
            }
            if(count!=0) {
                ans.push_back(tmp/count);
                tmp=0;
                count=0;
            }
        }
        return ans;
    }
};