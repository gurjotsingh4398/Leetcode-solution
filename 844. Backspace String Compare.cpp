// https://leetcode.com/problems/backspace-string-compare/

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> stk;
        for(char c : S) {
            if(c=='#') {
                if(!stk.empty()) stk.pop();
            } else {
                stk.push(c);
            }
        }
        S="";
        while(!stk.empty()) {
            S= stk.top() + S;
            stk.pop();
        }
        for(char c : T) {
            if(c=='#') {
                if(!stk.empty()) stk.pop();
            } else {
                stk.push(c);
            }
        }
        T="";
        while(!stk.empty()) {
            T= stk.top() + T;
            stk.pop();
        }
        if(S==T) return true;
        return false;
    }
};