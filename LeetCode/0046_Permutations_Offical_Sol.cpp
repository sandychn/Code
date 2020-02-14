// Time  : 4 ms (98.09%)
// Memory: 9.5 MB (33.78%)

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backtrack(ans, nums, 0);
        return ans;
    }

    void backtrack(vector<vector<int>>& ans, vector<int>& nums, int pos) {
        if (pos >= nums.size()) {
            ans.emplace_back(nums);
            return;
        }
        for (int i = pos; i < nums.size(); i++) {
            swap(nums[pos], nums[i]);
            backtrack(ans, nums, pos + 1);
            swap(nums[pos], nums[i]);
        }
    }
};
