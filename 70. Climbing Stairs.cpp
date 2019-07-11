// https://leetcode.com/problems/climbing-stairs/

class Solution {
public:
    int climbStairs(int n) {
        int arr[n+1];
        arr[0]=1;
        if(n==0) return 1; 
        arr[1]=1;
        for(int i=2;i<=n;i++) {
            arr[i]=arr[i-1]+arr[i-2];
        }
        return arr[n];
    }
};