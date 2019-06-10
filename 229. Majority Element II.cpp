// https://leetcode.com/problems/majority-element-ii/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int m1,count1=0,m2,count2=0,ptr=0,n=nums.size();
        while(ptr<n) {
            if(count1==0) {
                if(count2!=0 && nums[ptr]==m2) {
                    count2++;
                } else {
                    m1=nums[ptr];
                    count1++;
                }
            }
            else if(count2==0) {
                if(count1!=0 && nums[ptr]==m1) {
                    count1++;
                } else {
                    m2=nums[ptr];
                    count2++;
                }
            }
            else if(nums[ptr]==m1) count1++;
            else if(nums[ptr]==m2) count2++;
            else {
                count1--;
                count2--;
            }
            ptr++;
        }
    int c1=0,c2=0;
    vector<int>res;
    if(count1>0) {
        for(int i=0;i<n;i++) {
            if(nums[i]==m1) c1++;
        }
        if(c1>(n/3)) res.push_back(m1);
    }
    if(count2>0) {
        for(int i=0;i<n;i++) {
            if(nums[i]==m2) c2++;
        }
        if(c2>(n/3)) res.push_back(m2);
    }
    return res;    
  }
};