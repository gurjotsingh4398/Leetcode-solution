// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

class Solution {
public:
    int countDays(vector<int>& weights, int mid){
        int total_weight=0;
        int days =1;
        for(int i=0;i<weights.size();i++){
            if(total_weight+weights[i] > mid){
                total_weight = weights[i];
                days +=1;
            }
            else total_weight+=weights[i];
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int D) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while(low<high){
            int mid = (low+high)/2;
            int days = countDays(weights, mid);
            if(days<=D) high = mid;
            else low = mid+1;
        }
        return high;
    }
};