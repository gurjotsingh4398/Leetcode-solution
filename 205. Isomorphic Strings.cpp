// https://leetcode.com/problems/isomorphic-strings/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> mp1;
        map<char,char> mp2;
        for (int i=0;i<s.size();i++){
            if (mp1.find(s[i])== mp1.end() && mp2.find(t[i]) == mp2.end()){
                mp1[s[i]] = t[i]; 
                mp2[t[i]] = s[i];
            }else{
                if (mp1[s[i]]!=t[i] || mp2[t[i]]!=s[i]){
                    return false;
                }
            }
        }
        return true;
    }
};