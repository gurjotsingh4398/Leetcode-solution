// https://leetcode.com/problems/power-of-two/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        // return (n & n-1)==0 ? 1 : 0;  not work for last two cases
        return n > 0 && !(n & (n - 1));
    }
};