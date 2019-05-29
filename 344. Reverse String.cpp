// https://leetcode.com/problems/reverse-string/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    void reverseString(vector<char>& s) {
        char temp;
        int i=0,j=s.size()-1;
        while(i<j) {
            temp=s[i];
            s[i]=s[j];
            s[j]=temp;
            i++;j--;
        }
    }
};