// https://leetcode.com/problems/maximum-gap/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Bucket{
public:
    bool used = false;
    int mx = INT_MIN;
    int mi = INT_MAX;
};

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        if(n<2) return 0;

        int mini=*min_element(nums.begin(),nums.end()),
            maxi=*max_element(nums.begin(),nums.end()),
            buckSize=max(1,(maxi-mini)/(n-1)),
            buckNum=(maxi-mini)/buckSize +1;
        int ans=0;
        vector<Bucket> buckets(buckNum);
        
        for(int x : nums) {
            buckets[(x-mini)/buckSize].used = true;
            buckets[(x-mini)/buckSize].mi = min(buckets[(x-mini)/buckSize].mi, x);
            buckets[(x-mini)/buckSize].mx = max(buckets[(x-mini)/buckSize].mx, x);
        }
        
        int prevMx = INT_MAX;
        for(int i=0; i<buckNum; i++){
            if(!buckets[i].used) continue;
            ans = max(ans, buckets[i].mi - prevMx);
            prevMx = buckets[i].mx;
        }
        
        return ans;
    }
};