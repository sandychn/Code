// Time  : 60 ms
// Memory: 16.4 MB

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int INF = 0x3F3F3F3F;
        vector<int> dp(amount + 1, INF);
        dp[0] = 0;
        for (int i = 0; i <= amount; i++) {
            for (int denomination : coins) {
                // "i + denomination <= amount", left hand side will overflow
                if (denomination <= amount - i) {
                    dp[i + denomination] = min(dp[i + denomination], dp[i] + 1);
                }
            }
        }
        return dp[amount] == INF ? -1 : dp[amount];
    }
};
