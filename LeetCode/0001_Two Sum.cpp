class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (size_t i = 0; i < nums.size(); ++i) {
            hash.emplace(nums[i], i);
            auto it = hash.find(target - nums[i]);
            if (it != hash.end() && it->second != i) {
                return vector<int>{i, it->second};
            }
        }
        return vector<int>();
    }
};