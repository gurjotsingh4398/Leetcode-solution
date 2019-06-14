// https://leetcode.com/problems/simplify-path/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    string simplifyPath(string path) {
        int n=path.length();
        string res="",tmp="";
        stack<string> stk;
        for(int i=0;i<n;i++) {
            tmp="";
            while(path[i]=='/') {
                i++;
            }
            while (i<n && path[i]!='/') { 
                tmp+=path[i]; 
                i++; 
            } 
            if(tmp=="..") {
                if(!stk.empty())
                    stk.pop();
            }
            else if(tmp==".") continue;
            else if(tmp.length()!=0) {
                stk.push(tmp);
            }
        }
        if(stk.empty()) res="/";
        while (!stk.empty()) { 
            string temp = stk.top(); 
            res= '/'+temp+res; 
            stk.pop(); 
        } 
        return res;
    }
};