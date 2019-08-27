// https://leetcode.com/problems/find-all-duplicates-in-an-array/


static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++) {
            if(nums[abs(nums[i])-1]>0) nums[abs(nums[i])-1]*=-1;
            else ans.push_back(abs(nums[i]));
        }
        return ans;
    }
};