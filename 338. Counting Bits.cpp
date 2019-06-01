// https://leetcode.com/problems/counting-bits/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(1,0);
            for (int i=1;i<=num;i++) {
                res.push_back(res[i >> 1] + (i & 1));
            }
        return res;
    }
};