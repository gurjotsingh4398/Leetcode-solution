// https://leetcode.com/problems/n-ary-tree-preorder-traversal/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();


class Solution {
public:
    void preorderUtil(Node* root, vector<int>& ans) {
        if(!root) return;

        ans.push_back(root->val);
        for(auto node : root->children) {
            preorderUtil(node, ans);
        }
        
    }
    
    vector<int> preorder(Node* root) {
        vector<int> ans;
        preorderUtil(root, ans);
        return ans;
    }
};