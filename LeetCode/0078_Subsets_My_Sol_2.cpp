// Time  : 4 ms (92.60%)
// Memory: 9.4 MB (28.30%)

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        for (int i = 0; i < (1 << nums.size()); i++) {
            vector<int> tmp;
            for (int j = 0, p = i; p; j++, p >>= 1) {
                if (p & 1) tmp.push_back(nums[j]);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
