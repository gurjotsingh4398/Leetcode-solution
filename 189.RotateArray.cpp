//  https://leetcode.com/problems/rotate-array/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

void reverse(vector<int>& arr,int s,int e) {
    while(s<e) {
        int temp = arr[s];
        arr[s] = arr[e];
        arr[e] = temp;
        s++;
        e--;
    }
}
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%(nums.size());
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
        }         
};
