// https://leetcode.com/problems/remove-outermost-parentheses/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    string removeOuterParentheses(string S) {
        int n=S.length();
        string res="";
        int cnt=0;
        for(char c : S) {
            if(c=='(') {
                if(cnt++) {
                    res+=c;
                }
            } else {
                if(--cnt) {
                    res+=c;
                }
            }
        }
        return res;
    }
};
