// https://leetcode.com/problems/grumpy-bookstore-owner/

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int n=customers.size();
        if(n==1) return customers[0];
        
        int ng_sum=0,sum=0;
        
        for(int i=0;i<n;i++) {
            if(grumpy[i]==0)
               ng_sum+=customers[i]; 
        }
        
        for(int i=0;i<X;i++) {
            if(grumpy[i]==1) {
                sum+=customers[i];
            }
        }
        
        int start=1, end=X;
        int max=sum;
        
        while(end<n) {
            if(grumpy[start-1]==1) {
                sum-=customers[start-1];
            }
            if(grumpy[end]==1) {
                sum+=customers[end];
            }
            if(sum>max) {
                max=sum;
            }
            start++;
            end++;
        }
        return max + ng_sum;
    }
};