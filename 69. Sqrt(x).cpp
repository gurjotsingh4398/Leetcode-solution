// https://leetcode.com/problems/sqrtx/

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 ) return  0 ;
        if(x==1) return 1;
        int l=0,r=x,mid;
        mid=l +((r-l)/2);
        while(l!=mid) {
            int a=x/mid;
            if(mid==a) return mid;
            if(mid<a) l=mid;
            else r=mid;
            mid=l +((r-l)/2);
        }
        return l;
    }
};