// https://leetcode.com/problems/combination-sum-ii/

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    
    void rec(vector<int>& candidates, int target,int sum,int index) {
        
//           if (target == 0) {
//             res.push_back(cur);
//             return;
//         }
        
//         for (int i=start; i<nums.size(); ++i) {
//             if (nums[i] > target)
//                 return;
//             if (i != start && nums[i] == nums[i-1]) continue;
//             cur.push_back(nums[i]);
//             dfs(nums, target-nums[i], cur, i+1, res);
//             cur.pop_back();
//         }
        
        
        for(int i=index;i<candidates.size();i++) {
            if(i!=index && candidates[i]==candidates[i-1]) continue;
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
                rec(candidates,target,sum,i+1);
                sum-=temp.back();
                temp.pop_back();
            }
        }
        return;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.size()==0) return ans;
        sort(candidates.begin(),candidates.end());
        rec(candidates,target,0,0);
        return ans;
        
    }
};