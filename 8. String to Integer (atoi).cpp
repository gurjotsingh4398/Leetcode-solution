// https://leetcode.com/problems/string-to-integer-atoi/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int myAtoi(string str) {
        int n = str.length();
        long res=0;
        int i=0,flag=0;
        while(i<n && str[i]==' ') {
            i++;
        }
        if(i==n || str[i]>=97 && str[i]<=122 || str[i]>=65 && str[i]<=90) return 0;
        int sign = str[i]=='-' ? -1 : 1;
        // cout<<str[i];
        int j = (str[i]=='-' || str[i]=='+') ? i+1 : i;
        while(j<n) {
            // cout<<res<<endl;
            if(str[j]>='0' && str[j]<='9') {
                flag=1;
                res = res * 10 + (str[j] - '0');
                if (INT_MAX < res && sign == 1)
                    return INT_MAX;
                if (sign == -1 && (-res) < INT_MIN)
                    return INT_MIN;
            }  else if (!flag) {
                return 0;
            } else {
                return flag == 0 ? sign*res : (flag == 1 ? sign*res : 0);
            }
            j++;
        }
        return flag == 0 ? sign*res : (flag == 1 ? sign*res : 0);
    }
};
