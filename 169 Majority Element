https://leetcode.com/problems/majority-element/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> umap;
        for(int i=0;i<nums.size();i++) {
            umap[nums[i]]++;
        }
        int max=0;
        int ans;
        unordered_map<int, int>:: iterator p;
        for(p=umap.begin();p!=umap.end();p++) {
            if(p->second > max) {
                max=p->second;
                ans=p->first;
            }
        }
        return ans;
    }
};
