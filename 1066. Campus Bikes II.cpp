// https://leetcode.com/contest/biweekly-contest-1/problems/campus-bikes-ii/

int dp[11][1024];
class Solution {
public:
    int _abs(int x)
    {
        return x>0?x:-x;
    }
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n=workers.size(),m=bikes.size();
        memset(dp,1,sizeof(dp));
        dp[0][0]=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<(1<<m);j++)
            {
                for(int k=0;k<m;k++)
                {
                    if(j&(1<<k))continue;
                    dp[i+1][j|(1<<k)]=min(dp[i+1][j|(1<<k)],dp[i][j]+_abs(workers[i][0]-bikes[k][0])+_abs(workers[i][1]-bikes[k][1]));
                }
            }
        }
        
        int ans=999999999;
        for(int i=0;i<(1<<m);i++)
        {
            ans=min(ans,dp[n][i]);
        }
        return ans;
    }
};
