// https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int getSum(vector<int>& A, int i, int j) {
        if(i==0) {
            return A[j];
        } else {
            return (A[j]-A[i-1]);
        }
    }
    
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
        int n=A.size();
        for(int i=1;i<n;i++) {
            A[i] = A[i]+A[i-1];
        }
        int max=0,sum;
        int i=0, j=i+L-1, p, q, t;
        while(j<n) {
            sum=getSum(A, i, j);
            if(n-(j+1)>=M) {
                p=j+1;
                q=j+M;
                while(q<n) {
                    t=sum+getSum(A, p, q);
                    if(t>max) max=t;
                    p++;q++;
                }
            }
            if(i>=M) {
                p=i-M;
                q=i-1;
                while(p>=0) {
                    t=sum+getSum(A, p, q);
                    if(t>max) max=t;
                    p--;q--;
                }
            }
            i++;j++;
        }
        return max;
    }
};