// https://leetcode.com/problems/longest-absolute-file-path/

class Solution {
public:
    int lengthLongestPath(string input) {
        int level=0;
        vector<int> levels(300, 0);
        bool isFile = false;
        int ans=0, length=0;
        for(char c : input) {
            switch(c) {
                case '\n': { 
                    level=0;
                    length=0;
                    isFile=false;
                    break; 
                }
                case '\t': { 
                    level++;
                    break;
                }
                case '.': {
                     isFile = true;
                }
                default:
                    length++;
                    levels[level] = length;
                    if(isFile){
                        ans = max(ans, accumulate(levels.begin(), levels.begin() + level + 1, 0) + level);
                    }
                    
            }
        }
        return ans;
    }
};