// https://leetcode.com/problems/partition-equal-subset-sum/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(),totalSum=0;
        for(int i=0;i<n;i++) {
            totalSum+=nums[i];
        }
        if(totalSum%2 != 0) return false;
        totalSum/=2;
        int dp[n][totalSum+1];
        for(int i=0;i<n;i++) dp[i][0]=1;
        
        for(int i=1;i<=totalSum;i++) {
            if(i==nums[0]) dp[0][i]=1;
            else dp[0][i]=0;
        }
        
        for(int i=1;i<n;i++) {
            for(int j=1;j<=totalSum;j++) {
              dp[i][j]=0;  
            }
        }
        
        for(int i=1;i<n;i++) {
            for(int j=1;j<=totalSum;j++) {
                if(dp[i-1][j]) dp[i][j] = dp[i-1][j];
                else if(j>=nums[i]) {
                    dp[i][j]=dp[i-1][j-nums[i]];
                }
            }
        }
        
        return dp[n-1][totalSum];
    }
};