// https://leetcode.com/problems/length-of-last-word/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size(), i=n-1, c=0;
        if(n==0) return 0;
        
        while(s[i]==' ') {
            i--;
            c++;
        }
        
        if(c==n) return 0;
        
        int ans=0;
        while(s[i]!=' ' && c<n) {
            c++;
            ans++;
            i--;
        }
        return ans;
    }
};