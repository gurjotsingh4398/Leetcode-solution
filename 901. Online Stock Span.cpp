// https://leetcode.com/problems/online-stock-span/

int optimization = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class StockSpanner {
public:
    stack<int> stk,stk2;
    StockSpanner() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
    }
    
    int next(int price) {
        int ans=1;
        if(stk.empty()) {
            stk.push(price);
            stk2.push(ans);
            return 1;
        }
        while(!stk.empty() && price>=stk.top()) {
            stk.pop();
            ans+=stk2.top();
            stk2.pop();
        }
        stk.push(price);
        stk2.push(ans);
        return ans;
    }
};
