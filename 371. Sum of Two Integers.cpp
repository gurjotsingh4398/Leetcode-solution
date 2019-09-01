// https://leetcode.com/problems/sum-of-two-integers/

class Solution {
public:
    int getSum(int a, int b) {
         while(b != 0) {
                int carry = a & b;
                a = a ^ b;
                b = (unsigned int)carry << 1;
        }
        return a;
    }
};