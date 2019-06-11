// https://leetcode.com/problems/unique-morse-code-words/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        int n=words.size();
        if(n==0) return 0;
        vector<string> a{".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_map<string,int> m;
        string tmp="";
        for(int i=0;i<n;i++) {
            string s=words[i];
            int sl=s.length();
            for(int j=0;j<sl;j++) {
                tmp+=a[s[j]-'a'];
            }
            m[tmp]++;
            tmp="";
        }
        return m.size();
    }
};