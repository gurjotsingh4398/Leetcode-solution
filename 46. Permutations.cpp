// https://leetcode.com/problems/permutations/

class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;
    
   void rec(vector<int>& nums, int n,int index) {
        if(index == n) {
            res.push_back(nums);
            return;
        }
        
        for(int i=index;i<n;i++) {
            swap(nums[i],nums[index]);
            rec(nums,n,index+1);
            swap(nums[i],nums[index]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return res;
        
        rec(nums,n,0);
        return res;
    }
};