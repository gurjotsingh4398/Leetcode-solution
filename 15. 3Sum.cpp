// https://leetcode.com/problems/3sum/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> res;
         if(n<3) return res; 
        sort(nums.begin(),nums.end());
        vector<int> temp(3);
        for(int i=0;i<n-2;i++) {
                int L=i+1,R=n-1;
                while(L<R) {
                    int sum=nums[i]+nums[L]+nums[R];
                    if(sum==0) {
                        temp[0]=nums[i];
                        temp[1]=nums[L];
                        temp[2]=nums[R];
                        res.push_back(temp);
                        
                        int l=nums[L],r=nums[R];
                        while(L<n && nums[L]==l) L++;
                        while(R>L && nums[R]==r) R--;
                    } else if(sum>0) {
                        R--;
                    } else {
                        L++;
                    }
                }
            int t2=nums[i];
            while(i+1<n && t2==nums[i+1]) i++;
        }
       return res; 
    }
};

