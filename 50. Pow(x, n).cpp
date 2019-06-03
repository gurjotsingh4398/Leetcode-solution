// https://leetcode.com/problems/powx-n/

class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(x==0) return 0; 
        bool sign = n>=0?true:false;
        double np=x;
        double res=1;
        long long nn=n;
        nn=abs(nn);
        cout<<nn;
        while (nn>0){
            if (nn%2==1){
                res = res * np;
            }
            np=np*np;
            nn=nn/2;
        }
        if(sign==true) return res;
        else return (1/res);
    }
};


