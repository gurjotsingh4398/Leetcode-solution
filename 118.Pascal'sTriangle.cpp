https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> arr(numRows, vector<int> (1, 1));
        
        for(int i = 1; i <numRows; i++) {
           for(int j=1;j<=i;j++) {
               if(i==j) {
                  arr[i].push_back(1);
               } else {
                  arr[i].push_back(arr[i-1][j-1]+arr[i-1][j]);
               }
           }
        }
      return arr;  
    }
};

