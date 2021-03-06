// https://leetcode.com/problems/fibonacci-number/

class Solution {
public:
    int fib(int N) {
        int a=0;
        int b=1;
        if(N==0) return 0;
        if(N==1) return 1;
        for(int i=2;i<=N;i++) {
            int c=a+b;
            a=b;
            b=c;
        }
        return b;
    }
};