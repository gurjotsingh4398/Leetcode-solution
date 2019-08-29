// https://leetcode.com/problems/array-nesting/

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n=nums.size();
        vector<bool> vis(n,false);
        int res = 0;
        for (int i=0;i<n;i++) {
            if(!vis[i]) {
                int start = nums[i], count = 0;
                do {
                    start = nums[start];
                    count++;
                    vis[start] = true;
                }
                while (start != nums[i]);
                res = max(res, count);
            }
        }
        return res;
    }
};