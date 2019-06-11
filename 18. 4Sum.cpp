// https://leetcode.com/problems/4sum/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> res;
         if(n<4) return res; 
        sort(nums.begin(),nums.end());
        vector<int> temp(4);
        for(int i=0;i<n-3;i++) {
            for(int j=i+1;j<n-2;j++) {
                int L=j+1,R=n-1;
                while(L<R) {
                    int sum=nums[i]+nums[j]+nums[L]+nums[R];
                    if(sum==target) {
                        temp[0]=nums[i];
                        temp[1]=nums[j];
                        temp[2]=nums[L];
                        temp[3]=nums[R];
                        res.push_back(temp);
                        
                        int l=nums[L],r=nums[R];
                        while(L<n && nums[L]==l) L++;
                        while(R>L && nums[R]==r) R--;
                    } else if(sum>target) {
                        R--;
                    } else {
                        L++;
                    }
                }
                int t1=nums[j];
                while(j+1<n && t1==nums[j+1]) j++;
            }
            int t2=nums[i];
            while(i+1<n && t2==nums[i+1]) i++;
        }
       return res; 
    }
};