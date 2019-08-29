// https://leetcode.com/problems/combination-sum-iii/

class Solution {
public:
    void backtrack(vector<vector<int>>& res, int k, int n, int size, int curr, int sum, vector<int> tmp) {
        if(size==k || curr>9) {
            if(sum==n && tmp.size()==k) res.push_back(tmp);
            return;
        }
        tmp.push_back(curr);
        backtrack(res, k, n, size+1, curr+1, sum+curr, tmp);
        tmp.pop_back();
        backtrack(res, k, n, size, curr+1, sum, tmp);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        backtrack(res, k, n, 0, 1, 0, vector<int>());
        return res;
    }
};