// https://leetcode.com/problems/next-greater-element-i/submissions/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        stack<int> stk;
        for(int n : nums2) {
            while(!stk.empty() && n>stk.top()) {
                m[stk.top()]=n;
                stk.pop();
            }
            stk.push(n);
        }
        for(int &i : nums1) {
            i= m.count(i) ? m[i] : -1;
        }
        return nums1;
    }
};