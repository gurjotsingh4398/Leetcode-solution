// https://leetcode.com/problems/score-of-parentheses/

class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> stk;
        int res=0;
        for(char c : S) {
            if(c=='(') {
                stk.push(-1);
            } else {
                int temp=0;
                while(stk.top()!=-1) {
                    temp+=stk.top();
                    stk.pop();
                }
                stk.pop();
                if(temp>0) {
                    stk.push(2*temp);
                } else {
                    stk.push(1);
                }
                
            }
        }
        while(!stk.empty()) {
            res+=stk.top();
            stk.pop();
        }
        return res;
    }
};