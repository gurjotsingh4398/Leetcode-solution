// https://leetcode.com/problems/shortest-palindrome/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    string shortestPalindrome(string s) {
        int n=s.length();
        string rev(s);
        reverse(rev.begin(), rev.end());
        string tmp=s + '$' + rev;
        int tl=tmp.length();
        
        int i=0,j=1,lps[tl];
        lps[0]=0;
        while(j<tl) {
            if(tmp[i]==tmp[j]) {
                i++;
                lps[j]=i;
                j++;
            } else {
                if(i!=0) {
                    i=lps[i-1];
                } else {
                    lps[j]=0;
                    j++;
                }
            }
        }

        return rev.substr(0,n-lps[tl-1]) + s;
    }
};
