// https://leetcode.com/problems/remove-vowels-from-a-string/

class Solution {
public:
    string removeVowels(string S) {
        string ans="";
        int n=S.length();
        for(int i=0;i<n;i++) {
            if(S[i]=='a' || S[i]=='e' || S[i]=='i' || S[i]=='o' || S[i]=='u') {}
            else ans.push_back(S[i]);
        }
        return ans;
    }
};