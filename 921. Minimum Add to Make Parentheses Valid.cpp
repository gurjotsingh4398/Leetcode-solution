// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

class Solution {
public:
    int minAddToMakeValid(string S) {
        int n=S.length();
        stack<int> stk;
        for(int i=0;i<n;i++) {
            if(!stk.empty() && stk.top()=='(' && S[i]==')') stk.pop();
            else stk.push(S[i]);
        }
        return stk.size();
    }
};

//************************************************************************************

class Solution {
public:
    int minAddToMakeValid(string S) {
        int ans = 0, bal = 0;
        for (int i = 0; i < S.length(); ++i) {
            bal += S[i] == '(' ? 1 : -1;
            if (bal == -1) {
                ans++;
                bal++;
            }
        }

        return ans + bal;
    }
};