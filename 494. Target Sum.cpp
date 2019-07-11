// https://leetcode.com/problems/target-sum/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum<S || (sum+S)%2!=0) return 0;
        sum = (sum+S)/2;
        vector<int> dp(sum+1, 0);
        dp[0]=1;
        for(int num : nums) {
            for(int i=sum;i>=num;i--) {
                dp[i]=dp[i]+dp[i-num];
            }
        }
        return dp[sum];
    }
};

//----------------------------------------------------------------------

class Solution {
public:
    int count(vector<int>& nums, int S,int i,int sum) {
        if(S==sum && i==nums.size()) return 1;
        if(i>=nums.size()) return 0;
            
        return  count(nums, S, i+1,sum+nums[i]) + count(nums, S, i+1,sum-nums[i]);
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        return count(nums, S, 0, 0);   
    }
};