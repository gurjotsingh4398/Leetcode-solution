// https://leetcode.com/problems/valid-palindrome/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool isPalindrome(string s) {
        if(s=="") return true;
        string str="";
        for(char c : s) {
            if(c>='a' && c<='z'|| c>='0' && c<='9') str+=c;
            if(c>='A' && c<='Z') str+=(c+32);
        }
        int i=0,j=str.size()-1;
        while(i<=j) {
            if(str[i]==str[j]) {
                i++;j--;
            } else {
                return false;
            }
        }
        return true;
    }
};