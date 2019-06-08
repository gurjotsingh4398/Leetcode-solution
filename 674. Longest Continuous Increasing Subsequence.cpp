// https://leetcode.com/problems/longest-continuous-increasing-subsequence/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return 1;
        int ans=0,c=1;
        for(int i=0;i<n-1;i++) {
            if(nums[i+1]>nums[i]) {
                c++;
            } else {
                ans=max(c,ans);
                c=1;
            }
        }
        ans=max(ans,c);
        return ans;
    }
};