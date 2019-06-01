// https://leetcode.com/problems/single-number-iii/

int optimization = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size(),sum=0;
        vector<int> res(2,0);
        for(int i=0;i<n;i++) {
            sum=sum^nums[i];
        }
        // int mask = 1;
        // while ((xor_sum & mask) == 0) {
        //     mask <<= 1;
        // }
        int mask = sum ^ (sum&(sum-1));
        int a=0,b=0;
        for(int i=0;i<n;i++) {
            if((mask&nums[i])>0) {
                a=a^nums[i];
            } else {
                b=b^nums[i];
            }
        }
        res[0]=a;
        res[1]=b;
        return res;
    }
};