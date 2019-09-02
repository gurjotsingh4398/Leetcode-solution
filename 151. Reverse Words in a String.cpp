// https://leetcode.com/problems/reverse-words-in-a-string/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string t="",ans="";
        for(int i=n-1;i>=0;i--) {
            if(s[i]!=' ') {
                t=s[i]+t;
            } else {
                if(t.size()>0) ans+=t+' ';
                t="";
            }
        }
        ans=ans+t;
        int j=ans.size()-1,c=0;
        while(ans[j]==' ') {
            c++;
            j--;
        }
        return ans.substr(0,ans.size()-c);
    }
};