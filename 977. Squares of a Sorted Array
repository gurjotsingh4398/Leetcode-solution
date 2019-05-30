//https://leetcode.com/problems/squares-of-a-sorted-array/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n=A.size();
        if(n==0) return A;
        for(int i=0;i<n;i++) {
            A[i] = A[i]*A[i]; 
        }
        int p=0,q=n-1;
        while(p<q) {
            if(A[p]>A[q]) {
                int temp=A[p];
                A[p]=A[q];
                A[q]=temp;
            }
            q--;
        }
       return A;
    }
};
