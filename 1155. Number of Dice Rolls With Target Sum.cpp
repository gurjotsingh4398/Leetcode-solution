// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
       vector<long long> dp(target + 1, 0);
        dp[0] = 1;
        for (int c = 0; c < d; c++)
            for (int i = target; i >= 0; i--) {
                dp[i] = 0;

                for (int x = 1; x <= f && x <= i; x++)
                    dp[i] = (dp[i] + dp[i - x]) % 1000000007;
            }

        return dp[target];
    }
};