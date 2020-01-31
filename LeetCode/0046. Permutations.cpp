// Time  : 0 ms (100.00%)
// Memory: 9.5 MB (37.08%)

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        dfs(ans, tmp, nums, 0);
        return ans;
    }

    void dfs(vector<vector<int>>& ans, vector<int>& now, const vector<int>& nums, int visit) {
        if (now.size() >= nums.size()) {
            ans.emplace_back(now);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!((visit >> i) & 1)) {
                now.push_back(nums[i]);
                dfs(ans, now, nums, visit | (1 << i));
                now.pop_back();
            }
        }
    }
};
