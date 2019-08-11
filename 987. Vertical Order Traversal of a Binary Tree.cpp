// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> answer;    
        if(!root) return answer;
        
        map<int, vector<pair<int,int>>> myMap;
        int h_dist = 0;
        int v_dist = 0;
        
        queue<pair<TreeNode*,pair<int,int>>> myQueue;
        myQueue.push( make_pair(root, make_pair(h_dist, v_dist)) );
        
        while(!myQueue.empty()){
            auto front = myQueue.front();
            myQueue.pop();
            auto currentNode = front.first;
            auto currentDistance = front.second;
            h_dist = (currentDistance).first;
            v_dist = (currentDistance).second;
            myMap[h_dist].push_back( make_pair(v_dist, currentNode->val) );

            auto leftChild = currentNode->left;
            auto rightChild = currentNode->right;
            if(leftChild) 
                myQueue.push( make_pair(leftChild, make_pair(h_dist-1,v_dist+1)) );
            if(rightChild)
                myQueue.push(make_pair(rightChild, make_pair(h_dist+1,v_dist+1)));
        }

        int lines = myMap.size();
        answer.resize(lines);

        int index = 0;
        for(auto ele : myMap)
        {
            auto row_vec = ele.second;
            sort(row_vec.begin(), row_vec.end());
            for(auto val : row_vec)
                answer[index].push_back(val.second);
            index++;
        }

        return answer;
    }
};