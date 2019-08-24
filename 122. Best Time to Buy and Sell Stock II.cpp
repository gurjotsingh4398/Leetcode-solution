// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

//-------------------------1st solutions---------------------------------

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int i=0, ans=0, valley, peak;
        
        while(i<n-1) {
            while(i<n-1 && prices[i]>=prices[i+1]) i++;
            valley=prices[i];
            
            while(i<n-1 && prices[i]<=prices[i+1]) i++;
            peak=prices[i];
            
            ans+=(peak - valley);
        }
        return ans;
    }
};

//-----------------------2nd solution (shorter and faster) ----------------

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i-1])
                ans += prices[i] - prices[i-1];
        }
        return ans;
    }
};