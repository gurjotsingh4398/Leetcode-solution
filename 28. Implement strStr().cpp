// https://leetcode.com/problems/implement-strstr/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int strStr(string haystack, string needle) {
        int hl=haystack.length(),nl=needle.length();
        if(nl==0) return 0;
        if(hl==0) return -1;
        
        int lps[nl],res=-1;
        lps[0]=0;
        int i=0,j=1;
        while(j<nl) {
            if(needle[i]==needle[j]) {
                i++;
                lps[j]=i;
                j++;
            } else {
                if(i!=0) i=lps[i-1];
                else lps[j++]=0;
            }
        }
        
        j=0;i=0;
        while(i<hl) {
            if(haystack[i]==needle[j]) {
                i++;
                j++;
            } 
            if(j==nl) {
                res=(i-j);
                break;
            }
            else if( i<hl && haystack[i]!=needle[j]) {
                if(j!=0) {
                  j=lps[j-1];  
                } else {
                  i++;  
                }
            }
        }
        
        return res;
        
    }
};
