// https://leetcode.com/problems/valid-parentheses/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(char c : s) {
            if(c=='(' || c=='{' || c=='[') {
                stk.push(c);
            } else {
                if(!stk.empty()) {
                    char a=stk.top();
                    if(a=='(' && c==')' || a=='[' && c==']' || a=='{' && c=='}') {
                       stk.pop(); 
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }
        return stk.empty();
    }
};