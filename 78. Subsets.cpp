// https://leetcode.com/problems/subsets/

class Solution {
public:
    vector<vector<int>> res;
    
    void dfs(vector<int>& nums, int idx,vector<int>& tmp) {
		if (idx == nums.size()) {
			res.push_back(tmp);
			return;
		}
		tmp.push_back(nums[idx]);
		dfs(nums, idx + 1, tmp);

		tmp.pop_back();
		dfs(nums, idx + 1, tmp);
	}
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> tmp;
        dfs(nums, 0, tmp);
        return res;
    }
};