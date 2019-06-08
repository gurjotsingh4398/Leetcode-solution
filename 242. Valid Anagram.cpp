// https://leetcode.com/problems/valid-anagram/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        vector<int> arr(26,0);
        for(char c : s) {
            arr[c-'a']++;
        }
        for(char c : t) {
            arr[c-'a']--;
        }
        for(int i=0;i<26;i++) {
            if(arr[i]) return false;
        }
        return true;
    }
};