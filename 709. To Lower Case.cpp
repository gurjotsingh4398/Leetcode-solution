// https://leetcode.com/problems/to-lower-case/

class Solution {
public:
    string toLowerCase(string str) {
        string low;
    
   for(int i=0;i<str.length();i++)
        low.push_back(tolower(str[i]));
    
    return low;
    }
};