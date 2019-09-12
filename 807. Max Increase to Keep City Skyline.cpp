// https://leetcode.com/problems/max-increase-to-keep-city-skyline/

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int> top, left;
        int max_c, max_r;
        for(int i=0;i<n;i++) {
            max_c=INT_MIN, max_r=INT_MIN;
            for(int j=0;j<n;j++) {
                max_r=max(max_r, grid[i][j]);
                max_c=max(max_c, grid[j][i]);
            }
            top.push_back(max_c);
            left.push_back(max_r);
        }
        int sum=0;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                sum+=(min(top[i], left[j])-grid[i][j]);
            }
        }
        return sum;
    }
};