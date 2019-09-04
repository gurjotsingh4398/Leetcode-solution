//  https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    void util(vector<string>& dict, vector<string>& ans, string digits, int i, string& str) {
        if(i==digits.size()) {
            ans.push_back(str);
            return;
        } 
        
        for(auto a: dict[digits[i] - '0']){
            str.push_back(a);
            util(dict,ans,digits,i+1,str);
            str.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0) return ans; 
        vector<string> dict{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string str="";
        util(dict, ans, digits, 0, str);
        return ans;
    }
};