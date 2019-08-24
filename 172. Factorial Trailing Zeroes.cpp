// https://leetcode.com/problems/factorial-trailing-zeroes/


static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int trailingZeroes(int n) {
        int c=0;
        for(long long i=5;n/i;i*=5) {
            c+=(n/i);
        }
        return c;
    }
};