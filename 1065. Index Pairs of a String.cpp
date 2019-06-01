// https://leetcode.com/contest/biweekly-contest-1/problems/index-pairs-of-a-string/

class Solution {
public:
    vector<int> search(string pat,string txt) { 
        int M =pat.length(); 
        int N =txt.length(); 
        int l[M];
        vector<int> temp;

        comp(pat, M, l); 

        int i = 0;
        int j = 0;
        while (i < N) { 
            if (pat[j] == txt[i]) { 
                j++; 
                i++; 
            } 

            if (j == M) { 
                temp.push_back(i-j);
                j = l[j - 1]; 
            } 

            else if (i < N && pat[j] != txt[i]) { 
                if (j != 0) 
                    j = l[j - 1]; 
                else
                    i = i + 1; 
            } 
        }
       return temp; 
    }
    
    void comp(string pat, int M, int* l) 
    { 
        int len = 0; 
        l[0] = 0;
        int i = 1; 
        while (i < M) { 
            if (pat[i] == pat[len]) { 
                len++; 
                l[i] = len; 
                i++; 
            } else { 
                if (len != 0) { 
                    len = l[len - 1]; 
                } else { 
                    l[i] = 0; 
                    i++; 
                } 
            } 
        } 
    } 
    

    
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        vector<vector<int>> res;
        vector<int> temp(2,0),a;
        for(int i=0;i<words.size();i++) {
            string s=words[i];
            int l=s.length();
            a=search(s,text);
            for(int j=0;j<a.size();j++) {
                temp[0]=a[j];
                temp[1]=a[j]+l-1;
                res.push_back(temp);
            }
        }
       sort(res.begin(),res.end()); 
       return res; 
    }
};