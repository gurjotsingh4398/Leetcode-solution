// https://leetcode.com/problems/n-ary-tree-level-order-traversal/

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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<Node *> q1, q2;
        Node* t;
        vector<int> arr;
        q1.push(root);
        while(!q1.empty() || !q2.empty()) {
            
            while(!q1.empty()) {
                t = q1.front();
                q1.pop();
                arr.push_back(t->val);
                for(auto i : t->children) {
                    if(i) q2.push(i);
                }
            }
            if(arr.size()>0) ans.push_back(arr);
            arr.clear();
            
            while(!q2.empty()) {
                t = q2.front();
                q2.pop();
                arr.push_back(t->val);
                for(auto i : t->children) {
                    if(i) q1.push(i);
                }
            }
            if(arr.size()>0) ans.push_back(arr);
            arr.clear();
        }
        return ans;
    }
};

