// https://leetcode.com/problems/pancake-sorting/

class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        int n=A.size();
        vector<int> ans;
        
        for(int i=n-1;i>=0;i--) {
            auto max_it = max_element(A.begin(), A.begin()+i+1);
            if(*max_it!=A[i]) {
                reverse(A.begin(), max_it+1);
                ans.push_back(max_it+1-A.begin());
                reverse(A.begin(), A.begin()+i+1);
                ans.push_back(A.begin()+i+1-A.begin());
            }
        }
        return ans;
    }
};