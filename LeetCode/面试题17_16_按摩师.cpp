// Time  : 0 ms
// Memory: 9 MB

class Solution {
public:
    int massage(vector<int>& nums) {
        int last1 = 0; // 取nums[i-1]的答案最大值
        int last2 = 0; // 不取nums[i-1]的答案最大值
        for (size_t i = 0; i < nums.size(); i++) {
            int here = max(last1, last2 + nums[i]);
            last2 = max(last2, last1);
            last1 = here;
        }
        return max(last1, last2);
    }
};
