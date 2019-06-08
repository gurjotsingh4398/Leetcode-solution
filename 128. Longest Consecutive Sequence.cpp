// https://leetcode.com/problems/longest-consecutive-sequence/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return 1;
        
        map<int,int> m;
        for(int i=0;i<n;i++) {
            m[nums[i]]=1;
        }
        int c,ans=0;
        for(int i=0;i<n;i++) {
            c=1;
            if(m[nums[i]]==1) {
                int x=nums[i]-1;
                while(m[x]==1) {
                    c++;
                    m[x]++;
                    x--;
                }
                if(m[x]>1) c+=m[x];
                m[nums[i]]=c;
                ans=max(ans,c);
            }
        }
        return ans;
    }
};