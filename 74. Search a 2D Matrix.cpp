// https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.empty() == true) return false;
        if (matrix[0].empty() == true) return false;
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0, r = m * n - 1;
        while (l <= r){
            int mid = l + (r-l)/2;
            if (target == matrix[mid / m][mid % m])
                return true;
            if (matrix[mid / m][mid % m] < target)
                l = mid + 1;
            else 
                r = mid-1;
        }
        return false;
    }
};