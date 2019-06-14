// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    string removeDuplicates(string S) {
        if(S.size()==0) return S;
        string res= "";
        for(char c : S){
            if(c==res.back()) res.pop_back();
            else res.push_back(c);
        }
        return res;
    }
};