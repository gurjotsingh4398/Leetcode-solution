// https://leetcode.com/problems/letter-case-permutation/

class Solution {
public:
     char changeCase(char c){
          if (c >= 'a' && c <= 'z') 
            return c - 32;
          else  
            return c + 32;
    }
 
    void rec(string S,vector<string> &res,int index) {
        res.push_back(S);
        for(int i=index;i<S.length();i++) {
            if(S[i]<'0' || S[i]>'9') {
                S[i]=changeCase(S[i]);
                rec(S,res,i+1);
                S[i]=changeCase(S[i]);
            }
        }
    }
    
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        rec(S,res,0);
        sort(res.rbegin(),res.rend());
        return res;
    }
};