// https://leetcode.com/problems/happy-number/

class Solution {
public:
    bool isHappy(int n) {
        int t;
        int sum=0;
        unordered_set<int> hash;
        hash.insert(n);
        while(n>1) {
            while(n>0) {
                t=n%10;
                n=n/10;
                sum+=(t*t);
            }
            if(hash.count(sum)) return false;
            hash.insert(sum);
            n=sum;
            sum=0;
            
        }
        return n==1 ? true : false;
    }
};