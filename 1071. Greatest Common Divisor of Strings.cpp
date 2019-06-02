//https://leetcode.com/problems/greatest-common-divisor-of-strings/

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int a=str1.length(), b=str2.length();
        if (a > b) {
            swap(str1, str2);
            swap(a, b);
        }
        for (int i = a; i > 0; i--) {
            if ((a % i) || (b % i)) continue;  //substring length should divide both strings
            int flag = 0;
            //cheak presence of substring in str2
            for (int j=0;j<b;j++) if (str2[j]!=str1[j % i]) {
                flag=1;
                break;
            }
            if (flag) continue;
            //cheak presence of substring in str1
            for (int j=0; j<a;j++) if (str1[j] != str1[j % i]) {
                flag = 1;
                break;
            }
            if (flag) continue;
            return str1.substr(0, i);
        }
        return "";   
    }
};