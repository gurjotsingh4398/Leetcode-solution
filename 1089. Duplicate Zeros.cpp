// https://leetcode.com/problems/duplicate-zeros/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int i=0,n=arr.size();
        while(i<n) {
            if(arr[i]!=0) i++;
            else {
                for(int j=n-1;j>i+1;j--) {
                    arr[j]=arr[j-1];
                }
                if(i<n-1) arr[i+1]=0;
                i+=2;
            }
        }
    }
};