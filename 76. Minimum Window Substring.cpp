// https://leetcode.com/problems/minimum-window-substring/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    string minWindow(string s, string t) {
        int sl=s.length(),tl=t.length();
        if(sl==0 || tl==0) return "";
        
        vector<int> m(192,0);
        for(char c : t) m[c]++;
        
        int L=0,R=0,count=t.length();
        int res=INT_MAX,rL,rR;
        while(R<sl) {
            if(m[s[R]]>0) count--;
            m[s[R]]--;
            while(count==0) {
                if(res>(R-L)) {
                    res=R-L;
                    rL=L;
                    rR=R;
                }
                m[s[L]]++;
                if(m[s[L]]>0) count++;
                L++;
            }
            R++;
        }
        if(res > sl) return "";
        return s.substr(rL,(rR-rL+1));
        
    }
};