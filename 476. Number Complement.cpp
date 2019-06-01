// https://leetcode.com/problems/number-complement/

class Solution {
public:
    int findComplement(int num) {
        unsigned int mask = ~0;
        while (mask & num) mask = mask<<1;
        return ~num & ~mask;
    }
};