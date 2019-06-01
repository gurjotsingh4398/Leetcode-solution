// https://leetcode.com/problems/total-hamming-distance/

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res=0,n=nums.size();
        for (int j=0;j<32;j++) {
            int c=0;
            for (int i=0;i<n;i++) 
                c += (nums[i] >> j) & 1;
            res+=c*(n - c);
        }
        return res;
    }
};