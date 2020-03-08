// Time  : 12 ms
// Memory: 15.1 MB

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minValue = INT_MAX;
        for (int price : prices) {
            ans = max(ans, price - minValue);
            minValue = min(minValue, price);
        }
        return ans;
    }
};
