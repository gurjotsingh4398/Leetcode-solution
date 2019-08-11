// https://leetcode.com/problems/day-of-the-year/

class Solution {
public:
    bool checkYear(int year)  {  
        if (year % 400 == 0)  
            return true;  

        if (year % 100 == 0)  
            return false;  

        if (year % 4 == 0)  
            return true;  
        return false;  
    } 

    int dayOfYear(string date) {
        int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        string y=date.substr(0,4);
        string m=date.substr(5,2);
        string d=date.substr(8,2);
        int yy=stoi(y);
        int mm=stoi(m);
        int dd=stoi(d);
        int ans=0;
        for(int i=0;i<mm-1;i++) {
            ans+=days[i];
        }
        ans+=dd;
        if(mm>2 && checkYear(yy)) {
            ans+=1;
        }
        return ans;
    }
};