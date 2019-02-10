// https://leetcode.com/problems/pascals-triangle-ii/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> arr(rowIndex+1, vector<int> (1, 1));
        
        for(int i = 1; i <rowIndex+1; i++) {
           for(int j=1;j<=i;j++) {
               if(i==j) {
                  arr[i].push_back(1);
               } else {
                  arr[i].push_back(arr[i-1][j-1]+arr[i-1][j]);
               }
           }
        }
      return arr[rowIndex];  
    }
};
