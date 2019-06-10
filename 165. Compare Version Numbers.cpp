// https://leetcode.com/problems/compare-version-numbers/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> getVec(string ver) {
        string res="";
        vector<int> v;
        int n=ver.length();
        for(int i=0;i<n;i++) {
            if(ver[i]=='.') {
                v.push_back(stoi(res));
                res="";
            } else {
                res+=ver[i];
            }
        }
        v.push_back(stoi(res));
        return v;
        
    }
    
    int compareVersion(string version1, string version2) {
        auto v1=getVec(version1),v2=getVec(version2);
        while (v1.size() != v2.size()) {
            if(v1.size() < v2.size()) v1.push_back(0); 
            else v2.push_back(0);
        }
        if(v1==v2) return 0;
        if(v1<v2) return -1;
        else return 1;
    }
};