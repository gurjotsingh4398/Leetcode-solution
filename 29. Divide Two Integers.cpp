// https://leetcode.com/problems/divide-two-integers/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == - 1 )) return INT_MAX;
        long long res=0,temp=0,dd=abs((long  long)dividend),ds=abs((long  long)divisor);
        int sign = (dividend < 0 ) ^ (divisor < 0 ) ? -1 : 1; 
        
        for(int i=31;i>=0;i--) {
            if((temp + (ds<<i))<=dd) {
                temp+=(ds<<i);
                res = res | (1LL<<i);
            } 
        }
        
        return sign == 1 ? res : - res;
    }
};