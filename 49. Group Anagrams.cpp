// https://leetcode.com/problems/group-anagrams/



class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        
        for (auto s : strs) {
            string str = s;
            sort(str.begin(), str.end());
            m[str].push_back(s);
        }
        
        for (auto s : m) {
            res.push_back(s.second);
        }
        
        return res;
    }
};