// Time  : 36 ms (76.24%)
// Memory: 16.8 MB (19.66%)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> h;
        for (int val : nums) {
            if (!h.insert(val).second) {
                return true;
            }
        }
        return false;
    }
};
