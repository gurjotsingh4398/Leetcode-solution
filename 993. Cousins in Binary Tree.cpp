// https://leetcode.com/problems/cousins-in-binary-tree/

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
    pair<TreeNode*, int> visit(TreeNode* curr, TreeNode* parent, int x, int depth){
        if (!curr) return make_pair(nullptr, 0);
        if (curr->val == x) return make_pair(parent, depth);

        auto res1 = visit(curr->left, curr, x, depth+1);
        if (res1.first) return res1;

        auto res2 = visit(curr->right, curr, x, depth+1);
        if (res2.first) return res2;

        return make_pair(nullptr, 0);
}
    
    bool isCousins(TreeNode* root, int x, int y) {
        auto res1 = visit(root, nullptr, x, 0);    
        auto res2 = visit(root, nullptr, y, 0);    
        return res1.second == res2.second && res1.first != res2.first;
    }
};