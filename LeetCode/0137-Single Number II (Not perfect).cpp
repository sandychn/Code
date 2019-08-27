class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int val : nums) ++cnt[val];
        for (auto val : cnt) {
            if (val.second == 1) return val.first;
        }
        return -1;
    }
};