// https://leetcode.com/problems/sliding-window-maximum/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       vector<int> res;
        deque<int> max;
        for (int i = 0; i < nums.size(); ++i) {
            while (!max.empty() && nums[i] > max.back()) {
                max.pop_back();
            }
            max.push_back(nums[i]);
            if (i >= k - 1) {
                res.push_back(max.front());
                if (nums[i - k + 1] == max.front()) {
                    max.pop_front();
                }
            }
        }
        return res;
    }
};