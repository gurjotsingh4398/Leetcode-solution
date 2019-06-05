// https://leetcode.com/problems/palindrome-partitioning/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<vector<string>> res;
    vector<string> temp;
    
    bool isPal(string s) {
        int l=0,r=s.length()-1;
        while(l<=r) {
            if(s[l]==s[r]) {
                l++;
                r--;
            } else {
                return false;
            }
        }
        return true;
    }
    
    void rec(string s ,int n, int index) {
        if(n==index) {
            cout<<temp.size()-1<<" ";
            res.push_back(temp);
            return;
        }
        for(int i=index;i<n;i++) {
            if(isPal(s.substr(index,i+1-index))) {
                temp.push_back(s.substr(index,i+1-index));
                rec(s,n,i+1);
                temp.pop_back();
                
            }
        }
    } 
    
    vector<vector<string>> partition(string s) {
        int n=s.length();
        rec(s,n,0);
        return res;
    }
};