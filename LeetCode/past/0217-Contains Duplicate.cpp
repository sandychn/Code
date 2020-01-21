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