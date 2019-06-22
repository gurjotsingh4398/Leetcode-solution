// https://leetcode.com/problems/largest-rectangle-in-histogram/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        if(n==0) return 0;
        int i=0,area=0,max_area=0;
        stack<int> s;
        while(i<n) {
            if(s.empty() || heights[s.top()]<=heights[i]) s.push(i++);
            else {
                int tmp=s.top();
                s.pop();
                if(s.empty()) area=heights[tmp]*i;
                else {
                    area=heights[tmp]*(i-s.top()-1);
                }
                if(area>max_area) max_area=area;
            }
        }
        while(!s.empty()) {
            int tmp=s.top();
            s.pop();
            if(s.empty()) area=heights[tmp]*i;
            else {
                area=heights[tmp]*(i-s.top()-1);
            }
            if(area>max_area) max_area=area;
        }
        return max_area;
    }
};