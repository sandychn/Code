// Time  : 16 ms (94.95%)
// Memory: 11.1 MB (16.88%) 

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == candidate) {
                ++cnt;
            } else if (--cnt == 0) {
                candidate = nums[i];
                cnt = 1;
            }
        }
        return candidate;
    }
};