// https://leetcode.com/problems/roman-to-integer/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();


class Solution {
public:
    int romanToInt(string s) {
        int n=s.size();
        if(n==0) return 0;
        
        int map[26];
        map['I'-'A']=1;
        map['V'-'A']=5;
        map['X'-'A']=10;
        map['L'-'A']=50;
        map['C'-'A']=100;
        map['D'-'A']=500;
        map['M'-'A']=1000;
        
        int ans=0;
        for(int i=0;i<n-1;i++) {
            if(map[s[i]-'A']<map[s[i+1]-'A']) {
                ans-=map[s[i]-'A'];
            } else {
                ans+=map[s[i]-'A'];
            }
        }
        ans+=map[s[n-1]-'A'];
        return ans;
    }
};