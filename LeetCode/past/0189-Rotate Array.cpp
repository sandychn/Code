class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> tmp = nums;
        k %= nums.size();
        if (k == 0) return;
        for (int i = 0, j = nums.size() - k; i < tmp.size(); ++i, j = (j + 1) % tmp.size()) {
            nums[i] = tmp[j];
        }
    }
};