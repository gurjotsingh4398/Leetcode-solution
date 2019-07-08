// https://leetcode.com/problems/serialize-and-deserialize-bst/

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

class Codec {
public:
    
    void preorder(TreeNode* root, string& s) {
        if(!root) return;
        
        s+=(to_string(root->val))+" ";
        preorder(root->left,s);
        preorder(root->right,s);
    }
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        preorder(root, s);
        return s;
    }

    void insert(TreeNode* &root,vector<int> arr) {
        stack<TreeNode*> stk;
        root = new TreeNode(arr[0]);
        stk.push(root);
        int i=1;
        TreeNode* temp=NULL;
        for(int i=1;i<arr.size();i++) {
            temp=NULL;
            while(!stk.empty() && (stk.top()->val<arr[i])) {
                temp=stk.top();
                stk.pop();
            }
            
            if(temp==NULL) {
                stk.top()->left = new TreeNode(arr[i]);
                stk.push(stk.top()->left);
            } else {
                temp->right = new TreeNode(arr[i]);
                stk.push(temp->right);
            }
        }
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode *root=NULL;
        if(data == "") return root;
        
        vector<int> arr;
        stringstream ss{data}; 
        for (int i; ss >> i; ){   
            arr.push_back(i);
        }
        
        insert(root,arr);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));