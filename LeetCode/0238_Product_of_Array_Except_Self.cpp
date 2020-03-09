// Time  : 12 ms
// Memory: 17.9 MB

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            if (i) res[i] = res[i - 1] * nums[i];
            else res[i] = nums[i];
        }
        for (int i = n - 1, right = 1; i >= 0; i--) {
            if (i) {
                res[i] = res[i - 1] * right;
                right *= nums[i];
            } else {
                res[i] = right;
            }
        }
        return res;
    }
};
