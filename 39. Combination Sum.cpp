// https://leetcode.com/problems/combination-sum/

static const int fastIO = []() {  
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    
    void rec(vector<int>& candidates, int target,int sum,int index) {
        for(int i=index;i<candidates.size();i++) {
            sum=sum+candidates[i];
            temp.push_back(candidates[i]);
            if(sum==target) {
                ans.push_back(temp);
                sum-=temp.back();
                temp.pop_back();
                return;
            } else if(sum>target) {
                sum-=temp.back();
                temp.pop_back();
                return;
            } else {
                rec(candidates,target,sum,i);
                sum-=temp.back();
                temp.pop_back();
            }
        }
        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.size()==0) return ans;
        sort(candidates.begin(),candidates.end());
        rec(candidates,target,0,0);
        return ans;
        
    }
};