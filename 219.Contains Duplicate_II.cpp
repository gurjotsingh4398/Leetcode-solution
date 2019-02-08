//https://leetcode.com/problems/contains-duplicate-ii/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            auto it = map.find(nums[i]);
            if(it != map.end()) {
                if(i - it->second <= k)
                    return true;
            }
          map[nums[i]] = i;  
        }
       return false; 
    }
};
