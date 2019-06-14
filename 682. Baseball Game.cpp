// https://leetcode.com/problems/baseball-game/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();


class Solution {
public:
    int calPoints(vector<string>& ops) {
         if (ops.empty()) return 0;
        
        stack<int> stk;
        int ans = 0;
        
        for (int i=0; i<ops.size(); i++) {
            if (ops[i] == "C") {
                ans -= stk.top();
                stk.pop();
            } else if (ops[i] == "D") {
                stk.push(stk.top()*2);
                ans += stk.top();
            } else if (ops[i] == "+") {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.push(a);
                
                ans += (a+b);
                stk.push(a+b);
            } else {
                int n = stoi(ops[i]);
                ans += n;
                stk.push(n);
            }
        }
        
        return ans;
    }
};