// https://leetcode.com/problems/longest-common-prefix/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        
        if(n==0) return "";
        
        int minLen=strs[0].length();
        int temp;
        for(int i=1;i<n;i++) {
            temp=strs[i].length();
            minLen=min(minLen,temp);
        }
        int cnt=0;
        bool b=false;
        for(int i=0;i<minLen;i++) {
            char c=strs[0][i];
            for(int j=1;j<n;j++) {
              if(strs[j][i]!=c) {
                  b=true;
                  break;
              }
            }
            if(b) {
                break;
            } else {
                cnt++;
            }
        }
        return strs[0].substr(0,cnt);
    }
};