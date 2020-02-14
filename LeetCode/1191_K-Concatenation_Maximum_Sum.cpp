// Time  : 52 ms (71.08%)
// Memory: 14.4 MB (53.28%)

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int sumFromLeft = 0, maxFromLeft = 0;
        int sumFromRight = 0, maxFromRight = 0;
        int maxSubArray = 0, now = 0;
        for (int i = 0; i < arr.size(); i++) {
            maxFromLeft = max(maxFromLeft, sumFromLeft += arr[i]);
            maxFromRight = max(maxFromRight, sumFromRight += arr[arr.size() - 1 - i]);
            maxSubArray = max(maxSubArray, now += arr[i]);
            now = max(0, now);
        }

        // now, sumFromLeft = sumFromRight = sum of arr.
        sumFromLeft %= MOD;
        maxFromLeft %= MOD;
        maxFromRight %= MOD;
        maxSubArray %= MOD;

        int result = maxSubArray;
        if (k >= 2) {
            if (sumFromLeft > 0) {
                result = max(result, int((maxFromRight + sumFromLeft * (k - 2LL) % MOD + maxFromLeft) % MOD));
            } else {
                result = max(result, (maxFromRight + maxFromLeft) % MOD);
            }
        }
        return result;
    }

private:
    static const int MOD = 1e9 + 7;
};
