// https://leetcode.com/problems/longest-substring-without-repeating-characters/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(n==0) return 0;
        int res=0,tmp=0,j=0;
        unordered_map<char,int> m;
        for(int i=0;i<n;i++) {
            if(m[s[i]]==0) {
                m[s[i]]++;
                tmp++;
                res=max(tmp,res);
            } else {
                m[s[j]]--;
                j++;tmp--;i--;
            }
        }
        return res;
    }
};