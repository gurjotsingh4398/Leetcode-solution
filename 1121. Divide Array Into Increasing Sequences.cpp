// https://leetcode.com/problems/divide-array-into-increasing-sequences/

class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int K) {
        int res = 0;
        map<int, int> m;
        for (int i = 0;i < nums.size();i++) {
            m[nums[i]]++;
            if (res < m[nums[i]]) {
                res = m[nums[i]];
            }
        }
        if(res<= nums.size()/K) return true;
        else return false;
    }
};