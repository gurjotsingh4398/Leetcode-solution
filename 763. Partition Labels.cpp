// https://leetcode.com/problems/partition-labels/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        int n=S.length();
        vector<int> end(26,-1);
        for(int i=0;i<n;i++) {
                end[S[i]-'a']=i;
        }
       int s=0,l=0;
       for(int i=0;i<n;i++) {
            l = max(l, end[S[i]-'a']);
             if (i == l) {
                res.push_back(l - s + 1 );
                s = i + 1 ;
            }
        } 
     
       return res; 
    }
};
