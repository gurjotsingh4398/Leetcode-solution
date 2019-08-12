// https://leetcode.com/problems/n-ary-tree-postorder-traversal/

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
    void postorderUtil(Node* root, vector<int>& ans) {
        if(!root) return;

        for(auto node : root->children) {
            postorderUtil(node, ans);
        }
        ans.push_back(root->val);
    }
    
    vector<int> postorder(Node* root) {
        vector<int> ans;
        postorderUtil(root, ans);
        return ans;
    }
};