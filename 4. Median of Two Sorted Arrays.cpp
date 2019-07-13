// https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        int n=(n1+n2)/2;
        if(n1==0) {
            if(n2%2==0) return ((nums2[n]+nums2[n-1])*1.0)/2;
            else return nums2[n];
        } else if(n2==0) {
            if(n1%2==0) return ((nums1[n]+nums1[n-1])*1.0)/2;
            else return nums1[n];
        }
        int p=0,q=0,curr=-1,prev=-1;
        
        for(int i=0;i<=n;i++) {
            if (p < n1 && q < n2) { 
                if(nums1[p]<nums2[q]) {
                    prev=curr;
                    curr=nums1[p];
                    p++;
                }
                else {
                    prev=curr;
                    curr=nums2[q];
                    q++;
                }
		    } 
            else if(p==n1) {
                prev=curr;
                curr=nums2[q];
                q++;
            }
            else if(q==n2) {
                prev=curr;
                curr=nums1[p];
                p++;
            }
            
        }
        if((n1+n2)%2==0) return ((curr+prev)*1.0)/2;
        return curr;
    }
};