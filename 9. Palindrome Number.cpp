// https://leetcode.com/problems/palindrome-number/

class Solution {
public:
    bool isPalindrome(int x) {
       if(x < 0 || (!(x%10) && x)) return false;
		
		int rev = 0;
		while(x > rev) {
			rev = rev*10 + x%10;
			x /= 10;
		}
		
		return (x == rev || x == rev/10);
    }
};

// -----------------------------------------------------------


class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        stringstream s;
        string str,rev;
        s << x;
        s >> str;
        rev=str;
        reverse(rev.begin(),rev.end());
        if(rev==str) return true;
        else return false;
    }
};