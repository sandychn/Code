// Time  : 4 ms (92.60%)
// Memory: 13 MB (8.16%)

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(res, nums, tmp, 0);
        return res;
    }

private:
    void dfs(vector<vector<int>>& res, const vector<int>& nums, vector<int>& now, int pos) {
        if (pos == nums.size()) {
            res.push_back(now);
            return;
        }
        now.push_back(nums[pos]);
        dfs(res, nums, now, pos + 1);
        now.pop_back();
        dfs(res, nums, now, pos + 1);
    }
};
