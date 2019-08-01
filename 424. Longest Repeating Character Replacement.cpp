// https://leetcode.com/problems/longest-repeating-character-replacement/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size(), i=0, j=0,rep=0;
        unordered_map<char, int> m;
        while(i<n) {
            m[s[i]]++;
            rep = max(rep, m[s[i]]);
            i++;
            if(i-j-rep>k) {
                m[s[j]]--;
                j++;
            }
        }
        return i-j;
    }
};