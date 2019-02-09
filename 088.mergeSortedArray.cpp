// https://leetcode.com/problems/merge-sorted-array/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j=0;
        if(nums2.size()==0) {
                return;
           } 
        else {
            for(int i=0;i<n;i++) {
                nums1.pop_back();
            } 
        cout<<nums1.size();
        }
        vector<int>::iterator it;
        it = nums1.begin();
        for(int i=0;j<n;) {
            if(i==m){
               nums1.insert(it,nums2[j]);
                it++;
                j++;
            }
            else if(nums2[j]<=nums1[i]) {
                nums1.insert(it,nums2[j]);
                j++;m++;
                i++;it++;
            }
            else{
                i++;
                it++;
            }
        }
    }
};
