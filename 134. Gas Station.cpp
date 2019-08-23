// https://leetcode.com/problems/gas-station/

static int speedup=[](){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tank=0, total=0, st=0, n=gas.size();
        for (int i = 0; i < n; i ++) {
            int dif =  gas[i]-cost[i];
            tank += dif;      
            total += dif;     
            if (tank < 0) {
                st = i + 1; 
                tank = 0;    
            }
        }

        return total < 0 ? -1 : st;
    }
};