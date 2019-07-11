// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
private:
    string int2string(int x){
        stringstream ss;
        ss << x;
        string tmp;
        ss >> tmp;
        return tmp;
    }
    int string2int(string s){
        stringstream ss;
        ss << s;
        int x;
        ss >> x;
        return x;
    }
    
public:
    queue<TreeNode*> q;
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        queue<TreeNode*> q1;
        string s="";
        q1.push(root);
        while(!q1.empty()) {
            TreeNode* tmp = q1.front();
            q1.pop();
            if(tmp) {
                s+= int2string(tmp->val) + " ";
                q1.push(tmp->left);
                q1.push(tmp->right);
            } else {
                s+= "n ";
            }
        }
        int n=s.size(), c=0;
        int i=n-1;
        while(s[i]==' ' || s[i]=='n') {
            c++;
            i--;
        }
        // cout<<s.substr(0,n-c);
        return s.substr(0,n-c);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data== "") return NULL;
        queue<TreeNode*> q2;
        stringstream ss{data}; 
        string s;
        ss >> s;
        TreeNode* root = new TreeNode(string2int(s));
        q2.push(root);
        
        while(!ss.eof()) {
            TreeNode* tmp=q2.front();
            q2.pop();
            if(tmp) {
                ss >> s;
                tmp->left = s != "n" ? new TreeNode(string2int(s)) : NULL;
                q2.push(tmp->left);
                if(!ss.eof()) {
                    ss >> s;
                    tmp->right = s != "n" ? new TreeNode(string2int(s)) : NULL;
                    q2.push(tmp->right);
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));