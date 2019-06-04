// https://leetcode.com/problems/gray-code/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        int i=1;
        while(n>0) {
            for(int j=i-1;j>=0;j--) {
                ans.push_back(ans[j]+i);
            }
            i*=2;
            n--;
        }
        return ans;
    }
};