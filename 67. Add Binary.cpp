// https://leetcode.com/problems/add-binary/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();


class Solution {
public:
    string addBinary(string a, string b) {
        int al=a.length(),bl=b.length();
        if(bl>al) {
            return addBinary(b,a);
        }
        int c=0;
        for(int i=al-1;i>=0;i--) {
            int p=a[i]-'0';
            int tmp=(bl-(al-i));
            int q=tmp>=0?b[tmp]-'0':0;
            a[i]=((p+q+c)%2)+'0';
            c=(p+q+c)/2;
        }
        if(c) a= "1"+a;
        return a;
    }
};
