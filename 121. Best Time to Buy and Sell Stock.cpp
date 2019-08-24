// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0) return 0;
        int ans[n],t=prices[0];
        
        for(int i=0;i<n;i++) {
            if(prices[i]<=t) t=prices[i];
            ans[i]=t;
        }
        
        t=prices[n-1];
        for(int i=n-1;i>=0;i--) {
            if(prices[i]>=t) t=prices[i];
            ans[i]=t-ans[i]; 
        }
        
        t=ans[0];
        for(int i : ans) {
            t = max(t, i);
        }
        return t;
    }
};